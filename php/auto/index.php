<?php include "templates/header.php"; ?>
<div class="container">
	<div class="row">
		<h3>Търсене на кола по регистрационен номер</h3>
	</div>
	<div class="row">
		<form id="searchForm" class="form-inline my-2 my-lg-0" action="carinfo.php">
		<input name="registration" class="form-control mr-sm-2" type="search" placeholder="Номер" aria-label="Search">
		<button id="searchBtn" class="btn btn-outline-success my-2 my-sm-0">Търси</button>
	</div>
	<div id="carInfo" class="row mt-5">

	</div>
</div>
<script>
	$("#searchForm").submit(false);
	$("#searchBtn").click(function () {
		$.get("carinfo.php?" + $("#searchForm").serialize(), function(data, status) {
			$("#carInfo").html(data);
		});
	});
</script>
<?php include "templates/footer.php"; ?>