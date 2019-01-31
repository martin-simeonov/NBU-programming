<?php
   	if (!isset($_SESSION)) {
		session_start();
	}
	$error = null;
   
    if($_SERVER["REQUEST_METHOD"] == "POST") {
		require_once("services/login_service.php");
		
		$login = new LoginService();
		
		$response = $login->doLogin($_POST['username'], $_POST['password']);
	  
		if($response->error == null) {
			if ($_POST['username'] == 'admin') {
				$_SESSION['admin'] = true;
				header("location: admin.php");
			} else {
				header("location: userhome.php");
			}
		} else {
			$error = $response->error;
		}
   }
?>
<?php include "templates/header.php"; ?>
<div class="container">
<form class="form-signin" action="" method="post">
	<h2>Вход</h2>

	<div class="form-label-group">
		<input name="username" type="text" id="inputUsername" class="form-control" placeholder="Потребителско име" required="" autofocus="">
		<label for="inputEmail">Потребителско име</label>
	</div>
	
	<div class="form-label-group">
		<input name="password" type="password" id="inputPassword" class="form-control" placeholder="Парола" required="">
		<label for="inputPassword">Парола</label>
	</div>
	<button class="btn btn-lg btn-primary btn-block" type="submit">Влез</button>
	</br>
	<?php if (isset($error)) { ?>
	<div class="alert alert-danger">
		<?= $error ?>
	</div>
	<?php } ?>
</form>
</div>
<?php include "templates/footer.php"; ?>