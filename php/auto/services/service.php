<?php
require_once("libraries/database.php");
class Service {
	public $database;
	public function __construct() {
		$this->database = new Database();
	}
}
?>