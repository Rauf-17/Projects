<?php
// Start the session
session_start();

// Check if the user is logged in
if (!isset($_SESSION['username'])) {
    
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
    <title>Admin Dashboard</title>
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
            position: relative;
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
        .nav-links {
            display: flex;
            flex-direction: column;
            align-items: center;
        }
        .nav-links a {
            text-decoration: none;
            color: white;
            background-color: #007BFF;
            padding: 12px; 
            margin: 8px 0; 
            width: 100%;
            max-width: 350px; 
            text-align: center;
            border-radius: 5px;
            transition: background-color 0.3s;
        }
        .nav-links a:hover {
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
    <a href="logout.php" class="logout-btn">LOGOUT</a>
    
    <div class="container">
        <h1>Welcome, <?php echo htmlspecialchars($_SESSION['username']); ?>!</h1>
        <div class="nav-links">
            <a href="all_products.php">ALL PRODUCTS</a>
            <a href="add_remove_product.php">ADD/REMOVE PRODUCTS</a>
            <a href="update_product_info.php">UPDATE PRODUCT INFO</a>
            <a href="order.php">VIEW ORDERS</a>
        </div>
    </div>
</body>
</html>
