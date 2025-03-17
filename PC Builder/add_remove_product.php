<?php
// Database connection
$host = "localhost";
$username = "root";
$password = "";
$database = "pc_builder";

$conn = new mysqli($host, $username, $password, $database);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$message = "";
$searchTerm = "";

// Handle form submission for adding a product
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['add_product'])) {
    $name = $_POST['name'];
    $description = $_POST['description'];
    $price = (float)$_POST['price'];
    $stock = (int)$_POST['stock'];
    $category = $_POST['category'];

    $stmt = $conn->prepare("INSERT INTO products (name, description, price, stock, category) VALUES (?, ?, ?, ?, ?)");
    $stmt->bind_param("ssdis", $name, $description, $price, $stock, $category);

    if ($stmt->execute()) {
        $message = "Product added successfully!";
    } else {
        $message = "Error adding product: " . $conn->error;
    }

    $stmt->close();
}

// Handle form submission for removing a product
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['remove_product'])) {
    $productId = (int)$_POST['product_id'];
    
    if ($productId > 0) {
        $stmt = $conn->prepare("DELETE FROM products WHERE id = ?");
        $stmt->bind_param("i", $productId);

        if ($stmt->execute()) {
            $message = "Product removed successfully!";
        } else {
            $message = "Error removing product: " . $conn->error;
        }

        $stmt->close();
    }
}

// If this is an AJAX request, return only the table content
if (isset($_GET['ajax'])) {
    $searchTerm = isset($_GET['search']) ? $_GET['search'] : '';
    $stmt = $conn->prepare("SELECT * FROM products WHERE name LIKE ? ORDER BY id DESC");
    $searchTerm = "%$searchTerm%";
    $stmt->bind_param("s", $searchTerm);
    $stmt->execute();
    $result = $stmt->get_result();
    
    while($row = $result->fetch_assoc()) {
        echo "<tr>";
        echo "<td>" . htmlspecialchars($row['id']) . "</td>";
        echo "<td>" . htmlspecialchars($row['name']) . "</td>";
        echo "<td>" . htmlspecialchars($row['description']) . "</td>";
        echo "<td>$" . htmlspecialchars(number_format($row['price'], 2)) . "</td>";
        echo "<td>" . htmlspecialchars($row['stock']) . "</td>";
        echo "<td>" . htmlspecialchars($row['category']) . "</td>";
        echo "<td>";
        echo "<button type='button' onclick='removeProduct(" . $row['id'] . ", \"" . htmlspecialchars($row['name']) . "\")' class='remove-btn'>Remove</button>";
        echo "</td>";
        echo "</tr>";
    }
    exit;
}

// Initial data load
$stmt = $conn->prepare("SELECT * FROM products ORDER BY id DESC");
$stmt->execute();
$result = $stmt->get_result();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Product Management</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            line-height: 1.6;
        }
        h1, h2 {
            color: #333;
        }
        form {
            margin-bottom: 20px;
            padding: 20px;
            border: 1px solid #ddd;
            border-radius: 8px;
            background-color: #f9f9f9;
        }
        label {
            display: block;
            margin-bottom: 5px;
            font-weight: bold;
        }
        input, textarea {
            width: 100%;
            padding: 8px;
            margin-bottom: 10px;
            border: 1px solid #ccc;
            border-radius: 4px;
            box-sizing: border-box;
        }
        input:focus, textarea:focus {
            outline: none;
            border-color: #007BFF;
            background-color: aliceblue;
        }
        button {
            background-color: #007BFF;
            color: white;
            padding: 10px 15px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            width: 100%;
        }
        button:hover {
            background-color: #0056b3;
        }
        .message {
            padding: 10px;
            margin: 10px 0;
            border-radius: 4px;
            background-color: #d4edda;
            color: #155724;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
        }
        th {
            background-color: #f4f4f4;
        }
        .remove-btn {
            background-color: #dc3545;
        }
        .remove-btn:hover {
            background-color: #c82333;
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
    <a href="admin_dashboard.php" style="display: inline-block; margin: 10px 0; padding: 10px 10px; background-color: #007BFF; color: white; text-decoration: none; border-radius: 5px;">Back to Dashboard</a>
    
    <h1>Product Management</h1>

    <?php if (!empty($message)): ?>
        <p class="message"><?php echo htmlspecialchars($message); ?></p>
    <?php endif; ?>

    <!-- Add Product Form -->
    <form method="POST" action="add_remove_product.php">
        <h2>Add Product</h2>
        <label for="name">Product Name:</label>
        <input type="text" id="name" name="name" required>
        
        <label for="description">Description:</label>
        <textarea id="description" name="description" required></textarea>
        
        <label for="price">Price:</label>
        <input type="number" id="price" name="price" step="0.01" required>
        
        <label for="stock">Stock:</label>
        <input type="number" id="stock" name="stock" required>
        
        <label for="category">Category:</label>
        <input type="text" id="category" name="category" required>
        
        <button type="submit" name="add_product">ADD PRODUCT</button>
    </form>

    <!-- Search Form -->
    <form method="GET" action="" id="searchForm" onsubmit="return false;">
        <label for="search">Search Product:</label>
        <input type="text" id="search" name="search" value="<?php echo htmlspecialchars($searchTerm); ?>" 
               placeholder="Search by product name" oninput="liveSearch(this.value)">
    </form>

    <!-- Remove Product Form (Hidden) -->
    <form id="removeForm" method="POST" action="add_remove_product.php" style="display: none;">
        <input type="hidden" id="product_id" name="product_id">
        <input type="hidden" name="remove_product" value="1">
    </form>

    <!-- Products Table -->
    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Description</th>
                <th>Price</th>
                <th>Stock</th>
                <th>Category</th>
                <th>Action</th>
            </tr>
        </thead>
        <tbody id="productsTableBody">
            <?php if ($result && $result->num_rows > 0): ?>
                <?php while($row = $result->fetch_assoc()): ?>
                    <tr>
                        <td><?php echo htmlspecialchars($row['id']); ?></td>
                        <td><?php echo htmlspecialchars($row['name']); ?></td>
                        <td><?php echo htmlspecialchars($row['description']); ?></td>
                        <td>$<?php echo htmlspecialchars(number_format($row['price'], 2)); ?></td>
                        <td><?php echo htmlspecialchars($row['stock']); ?></td>
                        <td><?php echo htmlspecialchars($row['category']); ?></td>
                        <td>
                            <button type="button" 
                                    onclick="removeProduct(<?php echo $row['id']; ?>, '<?php echo htmlspecialchars($row['name']); ?>')" 
                                    class="remove-btn">
                                REMOVE
                            </button>
                        </td>
                    </tr>
                <?php endwhile; ?>
            <?php else: ?>
                <tr>
                    <td colspan="7">No products found</td>
                </tr>
            <?php endif; ?>
        </tbody>
    </table>

    <script>
        let searchTimeout;

        function liveSearch(searchTerm) {
            clearTimeout(searchTimeout);
            
            searchTimeout = setTimeout(() => {
                fetch(`?ajax=1&search=${encodeURIComponent(searchTerm)}`)
                    .then(response => response.text())
                    .then(html => {
                        document.getElementById('productsTableBody').innerHTML = html || '<tr><td colspan="7">No products found</td></tr>';
                    })
                    .catch(error => console.error('Error:', error));
            }, 300); // Wait 300ms after last keypress before sending request
        }

        function removeProduct(id, name) {
            if (confirm('Are you sure you want to remove "' + name + '"?')) {
                document.getElementById('product_id').value = id;
                document.getElementById('removeForm').submit();
            }
        }
    </script>
</body>
</html>

<?php $conn->close(); ?>