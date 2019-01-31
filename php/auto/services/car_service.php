<?php
require_once("services/service.php");
require_once("models/car_model.php");
require_once("models/repair_model.php");
class CarService extends Service {
	public function __construct() {
		parent::__construct();
	}
	
	public function getCarById($id) {
		$this->database->query(sprintf("SELECT * FROM car 
				WHERE carId=%d", $id));
		$row = $this->database->fetch();
		$car = new Car();
		$car->id = $row['carId'];
		$car->registration = $row['registration'];
		$car->make = $row['make'];
		$car->model = $row['model'];
		$car->year = $row['year'];
		$car->mileage = $row['mileage'];
		$car->repairs = $this->getCarRepairs($car->id);
		return $car;
	}
	
	public function getCarByRegistration($registration) {
		$this->database->query(sprintf("SELECT * FROM car 
				WHERE registration='%s'",
				$this->database->escape($registration)));
		$row = $this->database->fetch();
		$car = new Car();
		$car->id = $row['carId'];
		$car->registration = $row['registration'];
		$car->make = $row['make'];
		$car->model = $row['model'];
		$car->year = $row['year'];
		$car->mileage = $row['mileage'];
		$car->repairs = $this->getCarRepairs($car->id);
		return $car;
	}
	
	public function getCarRepairs($carId) {
		$repairs = array();
		$this->database->query(sprintf("SELECT * FROM repair 
				WHERE carId=%d ORDER BY repairDate",
				$this->database->escape($carId)));
		while ($row = $this->database->fetch()) {
			$repair = new Repair();
			$repair->id = $row['repairId'];
			$repair->description = $row['description'];
			$repair->repairDate = $row['repairDate'];
			$repair->mileage = $row['mileage'];
			$repair->carId = $row['carId'];
			$repair->userId = $row['userId'];
			$repair->price = $row['price'];
			$repairs[] = $repair;
		}
		return $repairs;
	}
	
	public function getAllCars() {
		$cars = array();
		$this->database->query("SELECT * FROM car");
		while ($row = $this->database->fetch()) {
			$car = new Car();
			$car->id = $row['carId'];
			$car->registration = $row['registration'];
			$car->make = $row['make'];
			$car->model = $row['model'];
			$car->year = $row['year'];
			$car->mileage = $row['mileage'];
			$cars[] = $car;
		}
		return $cars;
	}
	
	public function addCar($make, $model, $year, $mileage, $registration) {
		$this->database->query(sprintf("INSERT INTO car (registration,
				make, model, year, mileage) VALUES('%s', '%s', '%s',
				%d, %d)", $this->database->escape($registration),
				$this->database->escape($make),
				$this->database->escape($model), $year, $mileage));
	}
	
	public function addRepair($carId, $description, $date, $mileage, $userId, $price) {
		$this->database->query(sprintf("INSERT INTO repair (description,
				repairDate, mileage, carId, userId, price) VALUES ('%s', '%s',
				%d, %d, %d, %d)", $this->database->escape($description), 
				date("Y-m-d", strtotime($date)), $mileage, $carId, $userId, $price));
		
		// Check if repair mileage is greater than car mileage
		// and update if needed
		$car = $this->getCarById($carId);
		if ($mileage > $car->mileage) {
			$car->mileage = $mileage;
			$this->updateCar($car);
		}
	}
	
	public function removeRepair($repairId) {
		$this->database->query(sprintf("DELETE FROM repair WHERE repairId=%d", $repairId));
	}
	
	public function updateCar($car) {
		$this->database->query(sprintf("UPDATE car SET registration='%s', make='%s', model='%s', 
				year=%d, mileage=%d WHERE carId=%d", $this->database->escape($car->registration),
				$this->database->escape($car->make), $this->database->escape($car->model),
				$car->year, $car->mileage, $car->id));
	}
	
}
?>