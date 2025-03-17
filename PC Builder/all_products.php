<?php
session_start();

// Check if the user is logged in
if (!isset($_SESSION['username'])) {
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

$searchTerm = isset($_GET['search']) ? $_GET['search'] : '';

$query = "SELECT id, name, description, price, category FROM products";
if ($searchTerm) {
    $query .= " WHERE name LIKE '%$searchTerm%' OR description LIKE '%$searchTerm%' OR category LIKE '%$searchTerm%'";
}

$products = $conn->query($query);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>All Products</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f4f4f9;
        }
        .container {
            max-width: 1000px;
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
        .search-bar {
            margin-bottom: 20px;
            display: flex;
            justify-content: center;
        }
        .search-bar input {
            padding: 10px;
            width: 100%;
            max-width: 400px;
            border: 1px solid #ddd;
            border-radius: 5px;
            box-shadow: 0px 2px 4px rgba(0, 0, 0, 0.1);
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
            padding: 15px;
            text-align: left;
        }
        th {
            background-color: #007BFF;
            color: white;
        }
        tr:nth-child(even) {
            background-color: #f9f9f9;
        }
        tr:hover {
            background-color: #f1f1f1;
        }
        .highlight {
            background-color: yellow;
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
    <a href="logout.php" class="logout-btn">LOGOUT</a>
    <a href="admin_dashboard.php" style="display: inline-block; margin: 10px 0; padding: 10px 10px; background-color: #007BFF; color: white; text-decoration: none; border-radius: 5px;">Back to Dashboard</a>
        <h1>All Products</h1>
        <div class="search-bar">
            <input type="text" id="searchInput" placeholder="Search products..." value="<?php echo htmlspecialchars($searchTerm); ?>">
        </div>
        <table>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Name</th>
                    <th>Description</th>
                    <th>Price</th>
                    <th>Category</th>
                </tr>
            </thead>
            <tbody id="productsTableBody">
                <?php if ($products && $products->num_rows > 0): ?>
                    <?php while ($row = $products->fetch_assoc()): ?>
                        <tr>
                            <td><?php echo htmlspecialchars($row['id']); ?></td>
                            <td><?php echo htmlspecialchars($row['name']); ?></td>
                            <td><?php echo htmlspecialchars($row['description']); ?></td>
                            <td>$<?php echo number_format($row['price'], 2); ?></td>
                            <td><?php echo htmlspecialchars($row['category']); ?></td>
                        </tr>
                    <?php endwhile; ?>
                <?php else: ?>
                    <tr>
                        <td colspan="5">No products found.</td>
                    </tr>
                <?php endif; ?>
            </tbody>
        </table>
    </div>

    <script>
        const searchInput = document.getElementById('searchInput');
        const productsTableBody = document.getElementById('productsTableBody');

        searchInput.addEventListener('input', function() {
            const searchTerm = searchInput.value;
            fetch(`all_products.php?search=${encodeURIComponent(searchTerm)}`)
                .then(response => response.text())
                .then(html => {
                    const parser = new DOMParser();
                    const doc = parser.parseFromString(html, 'text/html');
                    const newTableBody = doc.getElementById('productsTableBody').innerHTML;
                    productsTableBody.innerHTML = newTableBody;
                    if (searchTerm) {
                        highlightSearchTerms(searchTerm);
                    }
                })
                .catch(error => console.error('Error:', error));
        });

        function highlightSearchTerms(searchTerm) {
            const content = productsTableBody.innerHTML;
            const regex = new RegExp(`(${searchTerm})`, 'gi');
            const highlightedContent = content.replace(regex, '<span class="highlight">$1</span>');
            productsTableBody.innerHTML = highlightedContent;
        }
    </script>
</body>
</html>