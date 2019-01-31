<?php
	require_once("services/car_service.php");

	if (!isset($_SESSION)) {
		session_start();
	}
	
	if(!isset($_SESSION['user_id'])){
		header("location:login.php");
		die();
	}
	
	if (!isset($_SESSION['car_id'])) {
		header("location:userhome.php");
		die();
	}
	
	$carService = new CarService();
	$car = $carService->getCarById($_SESSION['car_id']);
	
	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		$response = $carService->addRepair($car->id, $_POST['description'], $_POST['repairDate'],
					$_POST['mileage'], $_SESSION['user_id'], $_POST['price']);
		header("location: userhome.php");
    }
?>
<?php include "templates/header.php"; ?>
<div class="container">
	<form action="" method="post" >
		<h2>Добави ремонт за <?=$car->registration?></h2>
		<div class="form-row">
			<div class="form-group col-md-6">
				<label for="description">Описание на ремонта</label>
				<textarea name="description" class="form-control" id="description" placeholder="Описание на ремонта" rows="5" required="" ></textarea>
			</div>
		</div>
		<div class="form-row">
			<div class="form-group col-md-3">
				<label for="repairDate">Дата</label>
				<input class="form-control" type="date" value="<?=date("Y-m-d")?>" id="repairDate" name="repairDate" required="">
			</div>
			<div class="form-group col-md-3">
				<label for="mileage">Текущи километри на колата</label>
				<input name="mileage" type="text" class="form-control" id="mileage" placeholder="Километри" required="">
			</div>
		</div>
			<div class="form-row">
			<div class="form-group col-md-3">
				<label for="repairDate">Цена на ремонт</label>
				<input name="price" type="number" class="form-control" id="price" placeholder="Цена" required="">
			</div>
		</div>
		<button type="submit" class="btn btn-primary">Добави</button>
	</form>
</div>
<?php include "templates/footer.php"; ?>