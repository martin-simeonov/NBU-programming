/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package amusementparkmanager.views.controllers;

import amusementparkmanager.services.ManagerService;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

/**
 * FXML Controller class
 *
 * @author Marto
 */
public class AddManagerController implements Initializable {

    @FXML
    public TextField managerName;

    @FXML
    public TextField managerSalary;

    @FXML
    public void addManager(Event action) {
        if (managerName != null && managerSalary != null
                && !managerName.getText().isEmpty() && !managerSalary.getText().isEmpty()) {
            ManagerService.addManager(managerName.getText(),
                    Double.parseDouble(managerSalary.getText()));
            // Close window
            Button btn = (Button) action.getSource();
            ((Stage) btn.getScene().getWindow()).close();
        } else {
            // TODO
            System.out.println("more info needed");
        }
    }

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }

}
