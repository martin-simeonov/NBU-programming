<?php
	require_once("services/car_service.php");

	if (!isset($_SESSION)) {
		session_start();
	}
	
	if(!isset($_SESSION['user_id'])){
		header("location:login.php");
		die();
	}
	
	$carService = new CarService();
	
	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		$response = $carService->addCar($_POST['make'], $_POST['model'],
					$_POST['year'], $_POST['mileage'], $_POST['registration']);
		header("location: userhome.php");
    }
?>
<?php include "templates/header.php"; ?>
<div class="container">
	<form action="" method="post" >
		<h2>Добави нова кола</h2>
		<div class="form-row">
			<div class="form-group col-md-3">
				<label for="make">Марка</label>
				<input name="make" type="text" class="form-control" id="make" placeholder="Марка" required="">
			</div>
			<div class="form-group col-md-3">
				<label for="model">Модел</label>
				<input name="model" type="text" class="form-control" id="model" placeholder="Модел" required="">
			</div>
		</div>
		<div class="form-row">
			<div class="form-group col-md-3">
				<label for="year">Година на производство</label>
				<input name="year" type="text" class="form-control" id="year" placeholder="Година на производство" required="">
			</div>
			<div class="form-group col-md-3">
				<label for="mileage">Текущи километри</label>
				<input name="mileage" type="text" class="form-control" id="mileage" placeholder="Километри" required="">
			</div>
		</div>
		<div class="form-row">
			<div class="form-group col-md-6">
				<label for="registration">Регистрационен номер</label>
				<input name="registration" type="text" class="form-control" id="registration" placeholder="Регистрационен номер" required="">
			</div>
		</div>
		<button type="submit" class="btn btn-primary">Добави</button>
	</form>
</div>
<?php include "templates/footer.php"; ?>