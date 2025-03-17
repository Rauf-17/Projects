<?php
session_start();

// Check if the user is logged in and is either a buyer or an admin
if (!isset($_SESSION['username']) || !in_array($_SESSION['role'], ['buyer', 'admin'])) {
    header("Location: login.php");
    exit();
}

// Database connection
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "pc_builder";

$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$username = $_SESSION['username'];
$role = $_SESSION['role'];

if ($role === 'admin') {
    // Admin can see all orders
    $orders = $conn->query("
        SELECT o.id AS order_id, o.order_date, o.total_price, o.order_status,
               od.quantity, od.price AS unit_price, p.name, o.username
        FROM orders o
        JOIN order_details od ON o.id = od.order_id
        JOIN products p ON od.product_id = p.id
    ");
} else {
    // Buyer can see only their orders
    $orders = $conn->query("
        SELECT o.id AS order_id, o.order_date, o.total_price, o.order_status,
               od.quantity, od.price AS unit_price, p.name
        FROM orders o
        JOIN order_details od ON o.id = od.order_id
        JOIN products p ON od.product_id = p.id
        WHERE o.username = '$username'
    ");
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>My Orders</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f4f4f9;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            padding: 20px;
            background-color: white;
            border-radius: 10px;
            box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.1);
        }
        h1 {
            text-align: center;
            color: #333;
            margin-bottom: 20px;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-bottom: 20px;
        }
        table, th, td {
            border: 1px solid #ddd;
        }
        th, td {
            padding: 10px;
            text-align: left;
        }
        th {
            background-color: #f4f4f4;
        }
        .message {
            margin-bottom: 20px;
            padding: 10px;
            background-color: #d4edda;
            color: #155724;
            border: 1px solid #c3e6cb;
            border-radius: 5px;
        }
        .error {
            background-color: #f8d7da;
            color: #721c24;
            border: 1px solid #f5c6cb;
        }
        .nav-buttons {
            display: flex;
            justify-content: space-between;
            margin-bottom: 20px;
        }
        .nav-buttons a {
            padding: 10px 15px;
            background-color: #007BFF;
            color: white;
            text-decoration: none;
            border-radius: 5px;
            transition: background-color 0.3s;
        }
        .nav-buttons a:hover {
            background-color: #0056b3;
        }
        .logout-btn {
            background-color: #ff4d4d;
        }
        .logout-btn:hover {
            background-color: darkred;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="nav-buttons">
            <a href="<?php echo $role === 'admin' ? 'admin_dashboard.php' : 'buyer_dashboard.php'; ?>">Back to Dashboard</a>
            <a href="logout.php" class="logout-btn">Logout</a>
        </div>
        <h1><?php echo $role === 'admin' ? 'All Orders' : 'My Orders'; ?></h1>
        <?php if (!empty($message)): ?>
            <div class="message <?php if (isset($error)) echo 'error'; ?>">
                <?php echo htmlspecialchars($message); ?>
            </div>
        <?php endif; ?>

        <?php if ($orders && $orders->num_rows > 0): ?>
            <table>
                <thead>
                    <tr>
                        <th>Order ID</th>
                        <th>Order Date</th>
                        <th>Product Name</th>
                        <th>Quantity</th>
                        <th>Unit Price</th>
                        <th>Total Price</th>
                        <th>Status</th>
                        <?php if ($role === 'admin'): ?>
                            <th>Username</th>
                        <?php endif; ?>
                    </tr>
                </thead>
                <tbody>
                    <?php while ($row = $orders->fetch_assoc()): ?>
                        <tr>
                            <td><?php echo htmlspecialchars($row['order_id']); ?></td>
                            <td><?php echo htmlspecialchars($row['order_date']); ?></td>
                            <td><?php echo htmlspecialchars($row['name']); ?></td>
                            <td><?php echo htmlspecialchars($row['quantity']); ?></td>
                            <td>$<?php echo number_format($row['unit_price'], 2); ?></td>
                            <td>$<?php echo number_format($row['quantity'] * $row['unit_price'], 2); ?></td>
                            <td><?php echo htmlspecialchars($row['order_status']); ?></td>
                            <?php if ($role === 'admin'): ?>
                                <td><?php echo htmlspecialchars($row['username']); ?></td>
                            <?php endif; ?>
                        </tr>
                    <?php endwhile; ?>
                </tbody>
            </table>
        <?php else: ?>
            <p>No orders found.</p>
        <?php endif; ?>
    </div>
</body>
</html>