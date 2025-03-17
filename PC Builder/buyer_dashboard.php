<?php
// Start the session
session_start();

// Check if the user is logged in and is a buyer
if (!isset($_SESSION['role']) || $_SESSION['role'] !== 'buyer') {
    header("Location: login.php");
    exit;
}
setcookie("username", $_SESSION['username'], time() + (15 * 24 * 60 * 60), "/");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Buyer Dashboard</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f9;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
        }
        .container {
            background-color: #f4f4f9;
            padding: 30px 40px;
            border-radius: 10px;
            box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.2);
            width: 100%;
            max-width: 600px;
            text-align: center;
        }
        h1 {
            color: #333;
            margin-bottom: 20px;
        }
        .dashboard-links {
            text-align: center;
            padding: 20px;
            border: 1px solid #ddd;
            border-radius: 10px;
            background-color: white;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        }
        .dashboard-links a {
            display: block;
            margin: 10px 0;
            padding: 15px;
            background-color: #28a745;
            color: white;
            text-decoration: none;
            border-radius: 5px;
        }
        .dashboard-links a:hover {
            background-color: #218838;
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
    <a href="logout.php" class="logout-btn">LOGOUT</a>
    <div class="container">
        <h1>Welcome, <?php echo htmlspecialchars($_SESSION['username']); ?>!</h1>
        <div class="dashboard-links">
            <a href="buy_products.php">BUY PRODUCTS</a>
            <a href="pc_build.php">BUILD A PC</a>
            <a href="order.php">VIEW ORDERS</a>
        </div>
    </div>
</body>
</html>