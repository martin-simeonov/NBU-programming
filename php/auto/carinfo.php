<?php
    require_once "services/car_service.php";
	
	if (!isset($_SESSION)) {
		session_start();
	}
	
	$carService = new CarService();
	
	if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_SESSION['user_id'])) {
		$carService->removeRepair($_POST["repairId"]);
	}
	
	if (isset($_GET['registration'])) {
		$registration = $_GET['registration'];
				
		$car = new Car();
		if (!empty($registration)) {			
			$car = $carService->getCarByRegistration($registration);
			if (isset($car->id)) {					
				// add car id to session
				$_SESSION['car_id'] = $car->id; 
?>
<div class="container">
	<div class="row">
		<h5><?=$car->make?> <?=$car->model?>, <?=$car->year?>, <?=$car->mileage?> km </h5>
	</div>
	
	<div class="row mt-2">
		<table class="table">
			<thead class="thead-dark">
				<tr>
					<th scope="col">Ремонт</th>
					<th scope="col">Дата</th>
					<th scope="col">Километри на колата</th>
					<th colspan="2">Цена на ремонта</th>
				</tr>
			</thead>
			<tbody>
				<?php foreach ($car->repairs as $repair) {?>
				<tr>
					<td><?=$repair->description?></td>
					<td><?=$repair->repairDate?></td>
					<td><?=$repair->mileage?> km</td>
					<?php if (isset($_SESSION['user_id']) && $_SESSION['user_id'] == $repair->userId) {?>
					<td>
						<?=$repair->price?> лв
					</td>
					<td>
						<a value="<?=$repair->id?>" class="btn btn-danger">Изтрий</a>
					</td>
					<?php } else { ?>
					<td>
						Недостъпно
					</td>
					<?php } ?>
				</tr>
				<?php } ?>
			</tbody>
		</table>
	</div>

<?php if (isset($_SESSION['user_id'])) { ?>
	<div class="row mt-2">
		<div class="form-group col-md-8">
			<a class="btn btn-dark" href="addrepair.php">Добави ремонт</a>
		</div>
		<div class="form-group col-md-4">
			<h4>Обща сума: <?php $sum = 0; foreach ($car->repairs as $repair) $sum += $repair->price; echo $sum; ?> лв</h4>
		</div>
	</div>
<?php }} else { ?>
			<div class="alert alert-warning">
				Няма кола с тази регистряция.
			</div>
<?php }} else { ?>
			<div class="alert alert-warning">
				Не е въведена регистряция.
			</div>
<?php }} ?>
</div>
<script>
	$(".btn-danger").click(function() {
		var id = $(this).attr('value');
		$.ajax({
			url: "carinfo.php",
			type: "post",
			data: {
				repairId:id 
			},
			success: function(response) {
				location.reload();
			},
			error: function(xhr) {
			
			}
		});
	});
</script>