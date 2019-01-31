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
	$cars = $carService->getAllCars();
?>
<?php include "templates/header.php"; ?>
<div class="container">
	<div class="row">
		<h2>Моите коли</h2>
	</div>
	<div class="row">
		<div class="col-md-3 col-md-offset-2">
			<div class="dropdown">
				<button id="carSelectBtn" class="btn btn-secondary dropdown-toggle" type="button" id="dropdownMenuButton" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
					Избери кола
				</button>
				<ul class="dropdown-menu" aria-labelledby="dropdownMenuButton">
					<?php foreach ($cars as $car) { ?>
					<li><a class="dropdown-item" value="<?=$car->registration?>" href="#"><?=$car->make?> <?=$car->registration?></a></li>
					<?php } ?>
				</ul>
			</div>
		</div>
		<div class="col-md-5">
			<a class="btn btn-dark" href="addcar.php">Добави нова кола</a>
		</div>
	</div>
	<div id="carInfo" class="row mt-5">

	</div>
</div>
<script>
	$(".dropdown-menu li a").click(function() {
		$("#carSelectBtn").text($(this).text());
		var carReg = $(this).attr('value');
		$.ajax({
			url: "carinfo.php",
			type: "get",
			data: {
				registration: carReg
			},
			success: function(response) {
				$("#carInfo").html(response);
			},
			error: function(xhr) {
			
			}
		});
	});
	$(".dropdown-menu li a").get(<?php if (isset($_SESSION["car_id"])) echo $_SESSION["car_id"] - 1; else 0; ?>).click();
</script>
<?php include "templates/footer.php"; ?>