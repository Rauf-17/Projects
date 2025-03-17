<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PC BUILD</title>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            margin: 0;
            padding: 0;
            min-height: 100vh;
            display: flex;
            justify-content: center;
            align-items: center;
            background: linear-gradient(135deg, #f5f7fa 0%, #c3cfe2 100%);
            text-align: center;
        }

        .container {
            background-color: white;
            padding: 2rem;
            border-radius: 10px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            max-width: 600px;
            margin: 20px;
            animation: fadeIn 0.5s ease-in;
        }

        h1 {
            color: #2c3e50;
            font-size: 2.5rem;
            margin-bottom: 1rem;
            border-bottom: 2px solid #3498db;
            padding-bottom: 0.5rem;
        }

        h2 {
            color: #e74c3c;
            font-size: 1.8rem;
            margin: 1rem 0;
        }

        h3 {
            color: #34495e;
            font-size: 1.4rem;
            margin: 1rem 0;
        }

        p {
            color: #7f8c8d;
            font-size: 1.1rem;
            line-height: 1.6;
            margin: 1rem 0;
        }

        .back-button {
            display: inline-block;
            margin-top: 20px;
            padding: 10px 20px;
            background-color: #3498db;
            color: white;
            text-decoration: none;
            border-radius: 5px;
            transition: background-color 0.3s ease;
        }

        .back-button:hover {
            background-color: #2980b9;
        }

        @keyframes fadeIn {
            from {
                opacity: 0;
                transform: translateY(-20px);
            }
            to {
                opacity: 1;
                transform: translateY(0);
            }
        }

        @media (max-width: 480px) {
            .container {
                margin: 10px;
                padding: 1rem;
            }

            h1 {
                font-size: 2rem;
            }

            h2 {
                font-size: 1.5rem;
            }

            h3 {
                font-size: 1.2rem;
            }

            p {
                font-size: 1rem;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Sorry, Sir</h1>
        <h2>Lack of Knowledge in Laravel</h2>
        <h3>Also, Due to shortage of time, We couldn't make it.</h3>
        <p>Our website is currently under maintenance. Please come back later.</p>
        <a href="buyer_dashboard.php" class="back-button">Back to Dashboard</a>
    </div>
</body>
</html>