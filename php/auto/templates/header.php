<?php
if (!isset($_SESSION)) {
	session_start();
}
?>					
<!doctype html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta http-equiv="x-ua-compatible" content="ie=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1">

	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/css/bootstrap.min.css" integrity="sha384-GJzZqFGwb1QTTN6wy59ffF1BuGJpLSa9DkKMp0DgiMDm4iYMj70gZWKYbI706tWS" crossorigin="anonymous">
	<link rel="stylesheet" href="css/login.css">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
	
	<title>База данни за ремонти</title>
</head>

<body>
	<nav class="navbar navbar-expand-lg navbar-light bg-light">
		<a class="navbar-brand" href="index.php">База данни за ремонти</a>
		<button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
			<span class="navbar-toggler-icon"></span>
		</button>

		<div class="collapse navbar-collapse" id="navbarSupportedContent">
			<ul class="navbar-nav mr-auto">
				<li class="nav-item active">
					<a class="nav-link" href="index.php">Търсене <span class="sr-only">(current)</span></a>
				</li>
				<?php					
					if(isset($_SESSION['user_id'])){?>
					<li class="nav-item active">
						<a class="nav-link" href="userhome.php">Начало</a>
					</li>
					<li class="nav-item active">
						<a class="nav-link" href="logout.php">Изход</a>
					</li>
				<?php } else { ?>
					<li class="nav-item active">
						<a class="nav-link" href="login.php">Вход</a>
					</li>
				<?php } ?>
			</ul>
		</div>
	</nav>