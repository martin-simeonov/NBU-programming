<?php
require_once("services/service.php");
require_once("models/login_model.php");
class LoginService extends Service {
	public function __construct() {
		parent::__construct();
	}
	
	public function doLogin($username, $password) {
		$response = new Login();
		$response->id = 1;
		if ($this->isValidCredentials($username, $password)) {
			$id = $this->getIDbyUsername($username);
			$_SESSION['user_id'] = $id;
			$response->error = null;
			$response->sessionid = session_id();
		}
		else {
			$response->error = "Wrong username/password.";
		}
		return $response;
	}
	
	private function isValidCredentials($username, $password) {
		$this->database->query(sprintf("SELECT id FROM users 
				WHERE username='%s' AND password=MD5('%s')",
				$this->database->escape($username),
				$this->database->escape($password)));
		if ($this->database->fetch()) {
			return true;
		}
		return false;
	}
	
	private function getIDbyUsername($username) {
		$this->database->query(sprintf("SELECT id FROM users 
				WHERE username='%s'",
				$this->database->escape($username)));
		if ($row = $this->database->fetch()) {
			return $row['id'];
		}
		return 0;
	}
}