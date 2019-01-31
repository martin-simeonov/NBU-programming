/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package amusementparkmanager.views.controllers;

import amusementparkmanager.services.ChildService;
import amusementparkmanager.services.ParkService;
import amusementparkmanager.entities.Child;
import amusementparkmanager.entities.Park;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

/**
 * FXML Controller class
 *
 * @author Marto
 */
public class VisitorsTabController implements Initializable {

    @FXML
    private TextField visitorName;

    @FXML
    private TextField visitorAge;

    @FXML
    private ChoiceBox visitorSelect;

    @FXML
    private ChoiceBox parkSelect;

    @FXML
    public void addVisitor(Event action) {
        if (visitorName != null && !visitorName.getText().isEmpty()
                && visitorAge != null && !visitorAge.getText().isEmpty()) {
            ChildService.addChild(visitorName.getText(), Integer.parseInt(visitorAge.getText()));
            visitorSelect.setItems(ChildService.getChildren());
        } else {
            // TODO
            System.out.println("more info needed");
        }
    }

    @FXML
    public void visitPark(Event action) {
        if (visitorSelect != null && visitorSelect.getValue() != null
                && parkSelect != null & parkSelect.getValue() != null) {
            Parent root;
            try {
                FXMLLoader loader = new FXMLLoader(getClass().getClassLoader().getResource(
                        "amusementparkmanager/views/VisitDialog.fxml"));
                VisitDialogController controller = new VisitDialogController();
                controller.initData((Park)parkSelect.getValue(), (Child)visitorSelect.getValue());
                loader.setController(controller);
                Stage stage = new Stage();
                stage.setTitle("Посещение");
                stage.setScene(new Scene(loader.load(), 340, 140));
                stage.show();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            // TODO
            System.out.println("more info needed");
        }
    }
    
    @FXML
    public void refresh(Event action) {
        initViews();
    }

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        initViews();
    }

    private void initViews() {
        visitorSelect.setItems(ChildService.getChildren());
        parkSelect.setItems(ParkService.getParks());
    }

}
