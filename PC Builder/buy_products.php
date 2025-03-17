<?php
session_start();

// Check if the user is logged in and is a buyer
if (!isset($_SESSION['username']) || $_SESSION['role'] !== 'buyer') {
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

$message = "";

// Fetch products from the database
$products = $conn->query("SELECT id, name, description, price FROM products");

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $product_id = intval($_POST['product_id']);
    $quantity = intval($_POST['quantity']);
    $username = $_SESSION['username']; // Use 'username' instead of 'user_id'

    // Fetch product details
    $product = $conn->query("SELECT price FROM products WHERE id = $product_id")->fetch_assoc();
    if (!$product) {
        $message = "Product not found.";
    } else {
        $price = $product['price'];
        $total_price = $quantity * $price;

        // Create a new order
        $stmt = $conn->prepare("INSERT INTO orders (username, order_date, total_price, order_status) VALUES (?, NOW(), ?, 'pending')");
        $stmt->bind_param("si", $username, $total_price);
        $stmt->execute();
        $order_id = $stmt->insert_id;
        $stmt->close();

        // Insert into order_details
        $stmt = $conn->prepare("INSERT INTO order_details (quantity, price, order_id, product_id) VALUES (?, ?, ?, ?)");
        $stmt->bind_param("iiii", $quantity, $price, $order_id, $product_id);
        $stmt->execute();
        $stmt->close();

        $message = "Order placed successfully!";
        header("Location: order.php");
        exit();
    }
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Buy Products</title>
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
        .product {
            border-bottom: 1px solid #ddd;
            padding: 20px 0;
            display: flex;
            flex-direction: column;
            align-items: flex-start;
        }
        .product h3 {
            margin: 0;
            color: #007BFF;
        }
        .product p {
            margin: 5px 0;
            color: #555;
        }
        .form-group {
            margin-top: 10px;
            display: flex;
            align-items: center;
        }
        .form-group label {
            margin-right: 10px;
            font-weight: bold;
        }
        .form-group input[type="number"] {
            width: 60px;
            padding: 5px;
            border: 1px solid #ddd;
            border-radius: 5px;
            margin-right: 10px;
        }
        .form-group button {
            padding: 10px 15px;
            background-color: #28a745;
            color: white;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s;
        }
        .form-group button:hover {
            background-color: #218838;
        }
        .message {
            margin-bottom: 20px;
            padding: 10px;
            background-color: #f8d7da;
            color: #721c24;
            border: 1px solid #f5c6cb;
            border-radius: 5px;
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
        position: absolute;
        top: 20px;
        right: 20px;
        background-color: #ff4d4d;
        color: white;
        padding: 12px 25px;
        border-radius: 5px;
        text-decoration: none;
        font-size: 1rem;
        transition: background-color 0.3s;
    }

    .logout-btn:hover {
        background-color: darkred;
    }
    </style>
</head>
<body>
    <div class="container">
        <a href="buyer_dashboard.php" style="display: inline-block; margin: 10px 0; padding: 10px 10px; background-color: #007BFF; color: white; text-decoration: none; border-radius: 5px;">Back to Dashboard</a>
        <a href="logout.php" class="logout-btn">Logout</a>
        <h1>Buy Products</h1>
        <?php if (!empty($message)): ?>
            <div class="message"> <?php echo htmlspecialchars($message); ?> </div>
        <?php endif; ?>

        <?php if ($products && $products->num_rows > 0): ?>
            <?php while ($row = $products->fetch_assoc()): ?>
                <div class="product">
                    <h3><?php echo htmlspecialchars($row['name']); ?></h3>
                    <p><?php echo htmlspecialchars($row['description']); ?></p>
                    <p>Price: $<?php echo number_format($row['price'], 2); ?></p>
                    <form method="POST" action="">
                        <div class="form-group">
                            <label for="quantity">Quantity:</label>
                            <input type="number" name="quantity" id="quantity" min="1" required>
                            <input type="hidden" name="product_id" value="<?php echo $row['id']; ?>">
                            <button type="submit">Buy Now</button>
                        </div>
                    </form>
                </div>
            <?php endwhile; ?>
        <?php else: ?>
            <p>No products available.</p>
        <?php endif; ?>
    </div>
</body>
</html>