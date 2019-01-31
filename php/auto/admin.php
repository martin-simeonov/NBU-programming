<?php	
	require_once('services/user_service.php');
   	
	if (!isset($_SESSION)) {
		session_start();
	}
	
	if (!$_SESSION['admin']) {
		header("location: login.php");
	}

	$userService = new UserService();
	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		if (isset($_POST['changePassword'])) {
			$response = $userService->changePassword($_POST['userId'], $_POST["changePassword"]);
		} else if (isset($_POST['userId'])) {
			$response = $userService->removeUser($_POST['userId']);
			$_SESSION['response'] = $response;
		} else {
			$response = $userService->addUser($_POST['username'], $_POST['password']);
			$_SESSION['response'] = $response;
		}
		header("location: admin.php");
    }
	
	$users = $userService->getAll();
?>
<!doctype html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta http-equiv="x-ua-compatible" content="ie=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1">

	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/css/bootstrap.min.css" integrity="sha384-GJzZqFGwb1QTTN6wy59ffF1BuGJpLSa9DkKMp0DgiMDm4iYMj70gZWKYbI706tWS" crossorigin="anonymous">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
	
	<title>Admin</title>
</head>
<div class="container">
	<div class="row mt-2">
		<table class="table">
			<thead class="thead-dark">
				<tr>
					<th scope="col">ID</th>
					<th colspan="3">Username</th>
				</tr>
			</thead>
			<tbody>
				<?php foreach ($users as $user) {?>
				<tr>
					<td><?=$user->id?></td>
					<td><?=$user->username?></td>
					<?php if ($user->username != "admin") { ?>
					<td>
						<a value="<?=$user->id?>" class="btn btn-danger">Remove</a>
					</td>
					<td>
						<div class="btn btn-warning">Change password
							<form class="changePasswordForm" style="display:none" action="" method="post">
								<input name="userId" type="hidden" value="<?=$user->id?>">
								<input name="changePassword" type="password" class="form-control" placeholder="New password" required>
								</br>
								<button class="btn btn-secondary btn-sm" type="submit" >Change</button>
							</form>
						</div>
					</td>
					<?php } ?>
				</tr>
				<?php } ?>
			</tbody>
		</table>
	</div>
	<?php if (isset($_SESSION['response'])) {?>
	<div class="row mt-2">
		<div class="alert alert-danger">
			<?=$_SESSION['response']?>
		</div>
	</div>
	<?php } ?>
	<div class="row mt-2">
		<form action="" method="post" >
		<div class="form-row">
			<div class="form-group col-md-5">
				<label for="username">Username</label>
				<input name="username" type="text" class="form-control" id="username" placeholder="Username" required="">
			</div>
			<div class="form-group col-md-5">
				<label for="password">Password</label>
				<input name="password" type="password" class="form-control" id="password" placeholder="Password" required="">
			</div>
		</div>
		<button type="submit" class="btn btn-dark">Add user
		</form>
	</div>
	<div class="row mt-4">
		<a href="logout.php"  class="btn btn-dark">Logout</a>
	</div>
</div>
<script>
	$("#changePasswordForm").hide();
	$(".btn-danger").click(function() {
		var id = $(this).attr('value');
		$.ajax({
			url: "admin.php",
			type: "post",
			data: {
				userId:id 
			},
			success: function(response) {
				location.reload();
			},
			error: function(xhr) {
			
			}
		});
	});
	$(".btn-warning").click(function(event) {
		$(this).find("form").show();
	});
</script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.6/umd/popper.min.js" integrity="sha384-wHAiFfRlMFy6i5SRaxvfOCifBUQy1xHdJ/yoi7FRNXMRBu5WHdZYu1hA6ZOblgut" crossorigin="anonymous"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/js/bootstrap.min.js" integrity="sha384-B0UglyR+jN6CkvvICOB2joaf5I4l3gm9GU6Hc1og6Ls7i6U/mkkaduKaBhlAXv9k" crossorigin="anonymous"></script>
</body>
</html>