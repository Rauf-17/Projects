<?php
session_start();

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

// Variable to store messages
$message = "";

// Handle form submission
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = trim($_POST['username']);
    $email = trim($_POST['email']);
    $password = $_POST['password'];
    $confirmPassword = $_POST['confirm_password'];
    $role = $_POST['role'];

    // Form validation
    if (empty($username) || empty($email) || empty($password) || empty($confirmPassword) || empty($role)) {
        $message = "<p style='color: red; text-align: center;'>All fields are required!</p>";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $message = "<p style='color: red; text-align: center;'>Invalid email format!</p>";
    } elseif ($password !== $confirmPassword) {
        $message = "<p style='color: red; text-align: center;'>Passwords do not match!</p>";
    } elseif (preg_match('/[A-Z]/', $username)) {
        $message = "<p style='color: red; text-align: center;'>Username cannot contain uppercase letters!</p>";
    } elseif (!preg_match('/^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$/', $password)) {
        $message = "<p style='color: red; text-align: center;'>Password must contain at least one number, one uppercase letter, one lowercase letter, and one special character!</p>";
    } else {
        // Hash the password
        $hashedPassword = password_hash($password, PASSWORD_BCRYPT);

        // Use prepared statements to insert user into database
        $stmt = $conn->prepare("INSERT INTO users (username, user_password, useremail, user_role) VALUES (?, ?, ?, ?)" );
        $stmt->bind_param("ssss", $username, $hashedPassword, $email, $role);

        if ($stmt->execute()) {
            $message = "<p style='color: green; text-align: center;'>User Registered Successfully!</p>";
        } else {
            $message = "<p style='color: red; text-align: center;'>Error: " . $stmt->error . "</p>";
        }

        $stmt->close();
    }
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sign Up</title>
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
            background: #f4f4f9;
            padding: 20px 30px;
            border-radius: 10px;
            box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.2);
            width: 100%;
            max-width: 400px;
        }
        h1 {
            margin-bottom: 20px;
            text-align: center;
            color: #333;
        }
        label {
            font-weight: bold;
            display: block;
            margin-bottom: 5px;
            color: #555;
        }
        .input-wrapper {
            display: flex;
            align-items: center;
            margin-bottom: 15px;
            position: relative;
        }
        input, select {
            flex: 1;
            padding: 10px;
            border: 1px solid rgb(2, 27, 53);
            border-radius: 5px;
            font-size: 14px;
            margin: 5px;
            width: 90%;
        }
        input:focus, select:focus {
            border-color: #007BFF;
            outline: none;
            background-color: aliceblue;
        }
        button {
            width: 100%;
            padding: 10px;
            background-color: #007BFF;
            color: #fff;
            border: none;
            font-weight: bold;
            cursor: pointer;
            border-radius: 5px;
            transition: background-color 0.3s ease;
        }
        button:hover {
            background-color: #0056b3;
        }
        .tooltip {
            margin-left: 10px;
            cursor: pointer;
            font-size: 14px;
        }
        .tooltip .tooltiptext {
            visibility: hidden;
            width: 250px;
            background-color: #f9f9f9;
            color: #000;
            text-align: left;
            border-radius: 5px;
            padding: 5px;
            position: absolute;
            z-index: 1;
            bottom: 130%;
            left: 50%;
            transform: translateX(-50%);
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
        }
        .tooltip:hover .tooltiptext {
            visibility: visible;
        }
        .show-password {
            margin-left: 10px;
            cursor: pointer;
            color: #007BFF;
            font-size: 14px;
        }
        .show-password:hover {
            text-decoration: underline;
        }
        .link {
            text-align: center;
            font-size: 14px;
        }
        .link a {
            color: #007BFF;
            text-decoration: none;
        }
        .link a:hover {
            text-decoration: underline;
        }
    </style>
    <script>
        function togglePassword(fieldId, toggleId) {
            var passwordField = document.getElementById(fieldId);
            var passwordToggle = document.getElementById(toggleId);
            if (passwordField.type === "password") {
                passwordField.type = "text";
                passwordToggle.textContent = "Hide";
            } else {
                passwordField.type = "password";
                passwordToggle.textContent = "Show";
            }
        }

        function validatePasswords() {
            var password = document.getElementById("password").value;
            var confirmPassword = document.getElementById("confirm-password").value;
            if (password !== confirmPassword) {
                alert("Passwords do not match!");
                return false;
            }
            return true;
        }
    </script>
</head>
<body>
    <div class="container">
        <?php if (!empty($message)) echo $message; ?>
        <h1>Sign Up</h1>
        <form method="POST" action="signup.php" onsubmit="return validatePasswords()">
            <label for="username">User Name</label>
            <div class="input-wrapper">
                <input type="text" id="username" name="username" placeholder="Enter your username" required>
                <span class="tooltip">ℹ️
                    <span class="tooltiptext">
                        <strong>Username Criteria:</strong>
                        <ul>
                            <li>Cannot contain uppercase letters</li>
                        </ul>
                    </span>
                </span>
            </div>

            <label for="email">Email</label>
            <input type="email" id="email" name="email" placeholder="example@gmail.com" required>

            <label for="password">Password</label>
            <div class="input-wrapper">
                <input type="password" id="password" name="password" placeholder="Enter a strong password" required>
                <span id="password-toggle" class="show-password" onclick="togglePassword('password', 'password-toggle')">Show</span>
                <span class="tooltip">ℹ️
                    <span class="tooltiptext">
                        <strong>Password Criteria:</strong>
                        <ul>
                            <li>At least 8 characters</li>
                            <li>Must contain at least one lowercase letter</li>
                            <li>Must contain at least one uppercase letter</li>
                            <li>Must contain at least one number</li>
                            <li>Must contain at least one special character</li>
                        </ul>
                    </span>
                </span>
            </div>

            <label for="confirm-password">Confirm Password</label>
            <div class="input-wrapper">
                <input type="password" id="confirm-password" name="confirm_password" placeholder="Re-enter your password" required>
                <span id="confirm-password-toggle" class="show-password" onclick="togglePassword('confirm-password', 'confirm-password-toggle')">Show</span>
            </div>

            <input type="hidden" name="role" id="role"  value="buyer">

            <br>
            <button type="submit">SIGN UP</button>
        </form>
        <p class="link">Already have an account? <a href="login.php">Login</a></p>
    </div>
</body>
</html>
