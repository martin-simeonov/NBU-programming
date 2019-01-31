<?php
require_once("models/user_model.php");
require_once("services/service.php");
class UserService extends Service {
	public function __construct() {
		parent::__construct();
	}
	
	public function getAll() {
		$users = array();
		$this->database->query("SELECT id, username FROM users");
		while ($row = $this->database->fetch()) {
			$user = new User();
			$user->id = $row['id'];
			$user->username = $row['username'];
			$users[] = $user;
		}
		return $users;
	}
	
	public function addUser($username, $password) {
		$this->database->query(sprintf("SELECT * FROM users WHERE username='%s'",
				$this->database->escape($username)));
		$row = $this->database->fetch();
		if ($row) {
			return "Username already exists";
		}
		$this->database->query(sprintf("INSERT INTO users (username, password)
				VALUES ('%s', MD5('%s'))", $this->database->escape($username),
				$this->database->escape($password)));
	}
	
	public function removeUser($userId) {
		$this->database->query(sprintf("SELECT * FROM users WHERE id=%d", $userId));
		$row = $this->database->fetch();
		if ($row['username'] == 'admin') {
			return "Can't delete admin";
		}
		$this->database->query(sprintf("DELETE FROM users WHERE id=%d", $userId));
	}
	
	public function changePassword($userId, $password) {
		$this->database->query(sprintf("UPDATE users SET password=MD5('%s') WHERE id=%d",
				$this->database->escape($password), $userId));
	}
}