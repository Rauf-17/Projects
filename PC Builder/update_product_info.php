<?php
// Enable error reporting for debugging
error_reporting(E_ALL);
ini_set('display_errors', 1);

// Database connection
$host = "localhost";
$username = "root";
$password = "";
$database = "pc_builder";

$conn = new mysqli($host, $username, $password, $database);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Fetch all products for selection in the dropdown
$products = [];
$sql = "SELECT id, name FROM products";
$result = $conn->query($sql);
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $products[] = $row;
    }
}

// Fetch product details if product_id is set and valid
$product = null;
if (isset($_POST['product_id'])) {
    $product_id = $_POST['product_id'];
    $sql = "SELECT * FROM products WHERE id = ?";
    $stmt = $conn->prepare($sql);
    if ($stmt) {
        $stmt->bind_param("i", $product_id);
        $stmt->execute();
        $result = $stmt->get_result();
        $product = $result->fetch_assoc();
        $stmt->close();
    }
}

// Handle form submission to update product details
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['update'])) {
    $id = $_POST['id'];
    $name = $_POST['name'];
    $description = $_POST['description'];
    $price = $_POST['price'];
    $stock = $_POST['stock'];
    $category = $_POST['category'];

    // Update SQL query
    $update_sql = "UPDATE products SET name = ?, description = ?, price = ?, stock = ?, category = ? WHERE id = ?";
    $stmt = $conn->prepare($update_sql);
    if ($stmt) {
        $stmt->bind_param("ssdiss", $name, $description, $price, $stock, $category, $id);
        $stmt->execute();
        $stmt->close();

        // Refresh the product data after update
        $sql = "SELECT * FROM products WHERE id = ?";
        $stmt = $conn->prepare($sql);
        $stmt->bind_param("i", $id);
        $stmt->execute();
        $result = $stmt->get_result();
        $product = $result->fetch_assoc();
        $stmt->close();
    } else {
        echo "Error updating product: " . $conn->error;
    }
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Update Product Info</title>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f7fc;
        }

        h1 {
            text-align: center;
            color: #333;
            margin-top: 20px;
        }

        .form-container {
            max-width: 600px;
            margin: 30px auto;
            padding: 20px;
            background-color: #fff;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            border-radius: 8px;
        }

        input[type="text"], input[type="number"], textarea, select {
            width: 100%;
            padding: 10px;
            margin: 10px 0;
            border-radius: 8px;
            border: 1px solid #ccc;
            font-size: 1rem;
        }

        input[type="submit"] {
            background-color: #007BFF;
            color: #fff;
            border: none;
            padding: 12px 20px;
            font-size: 1.1rem;
            cursor: pointer;
            border-radius: 8px;
        }

        input[type="submit"]:hover {
            background-color: #0056b3;
        }

        label {
            font-size: 1.1rem;
            margin-bottom: 5px;
        }

        table {
            width: 80%;
            margin: 20px auto;
            border-collapse: collapse;
        }

        table, th, td {
            border: 1px solid #ddd;
        }

        th, td {
            padding: 10px;
            text-align: center;
        }

        th {
            background-color: #007BFF;
            color: white;
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
            background-color: darkre;
        }

    </style>
</head>
<body>
    <a href="logout.php" class="logout-btn">LOGOUT</a>
    <a href="admin_dashboard.php" style="display: inline-block; margin: 10px 0; padding: 10px 15px; background-color: #007BFF; color: white; text-decoration: none; border-radius: 5px;">Back to Dashboard</a>

    <h1>Update Product Info</h1>

    <!-- Dropdown to select product -->
    <div class="form-container">
        <form method="POST" action="update_product_info.php">
            <label for="product_id">Select Product to Update</label>
            <select name="product_id" id="product_id" required>
                <option value="">--Select Product--</option>
                <?php foreach ($products as $product_item): ?>
                    <option value="<?php echo $product_item['id']; ?>"
                        <?php echo isset($product) && $product['id'] == $product_item['id'] ? 'selected' : ''; ?>>
                        <?php echo htmlspecialchars($product_item['name']); ?>
                    </option>
                <?php endforeach; ?>
            </select>

            <input type="submit" value="Load Product">
        </form>
    </div>

    <?php if ($product): ?>
        <!-- Product Update Form -->
        <div class="form-container">
            <form method="POST" action="update_product_info.php">
                <input type="hidden" name="id" value="<?php echo htmlspecialchars($product['id']); ?>">

                <label for="name">Product Name</label>
                <input type="text" id="name" name="name" value="<?php echo htmlspecialchars($product['name']); ?>" required>

                <label for="description">Product Description</label>
                <textarea id="description" name="description" rows="4" required><?php echo htmlspecialchars($product['description']); ?></textarea>

                <label for="price">Product Price ($)</label>
                <input type="number" id="price" name="price" value="<?php echo htmlspecialchars($product['price']); ?>" step="0.01" required>

                <label for="stock">Product Stock</label>
                <input type="number" id="stock" name="stock" value="<?php echo htmlspecialchars($product['stock']); ?>" required>

                <label for="category">Product Category</label>
                <input type="text" id="category" name="category" value="<?php echo htmlspecialchars($product['category']); ?>" required>

                <input type="submit" name="update" value="Update Product Info">
            </form>
        </div>

        <!-- Display Updated Product Info in a Table -->
        <h2>Updated Product Details</h2>
        <table>
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Description</th>
                <th>Price ($)</th>
                <th>Stock</th>
                <th>Category</th>
            </tr>
            <tr>
                <td><?php echo htmlspecialchars($product['id']); ?></td>
                <td><?php echo htmlspecialchars($product['name']); ?></td>
                <td><?php echo htmlspecialchars($product['description']); ?></td>
                <td><?php echo htmlspecialchars($product['price']); ?></td>
                <td><?php echo htmlspecialchars($product['stock']); ?></td>
                <td><?php echo htmlspecialchars($product['category']); ?></td>
            </tr>
        </table>
    <?php endif; ?>

</body>
</html>

<?php $conn->close(); ?>
