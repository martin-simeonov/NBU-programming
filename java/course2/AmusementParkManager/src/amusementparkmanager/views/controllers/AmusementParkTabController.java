/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package amusementparkmanager.views.controllers;

import amusementparkmanager.entities.Park;
import amusementparkmanager.services.ParkService;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.stage.Stage;

/**
 * FXML Controller class
 *
 * @author Marto
 */
public class AmusementParkTabController implements Initializable {

    @FXML
    private ComboBox parkSelect;

    @FXML
    private ListView installationList;

    @FXML
    private Label managerName;

    @FXML
    private Label managerSalary;
    
    @FXML
    private Label income;
    
    @FXML
    private Label averageAge;

    @FXML
    private void createAmusementPark(ActionEvent event) {
        Parent root;
        try {
            root = FXMLLoader.load(getClass().getClassLoader().getResource("amusementparkmanager/views/AmusementParkCreate.fxml"));
            Stage stage = new Stage();
            stage.setTitle("Добави увеселителен парк");
            stage.setScene(new Scene(root, 430, 500));
            stage.show();
            stage.setOnHiding((WindowEvent) -> {
                // Refresh parks list on closing add park window
                parkSelect.setItems(ParkService.getParks());
                parkSelect.getSelectionModel().selectLast();
            });
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @FXML
    public void refresh() {
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
        // Initialize park list
        parkSelect.setItems(ParkService.getParks());
        parkSelect.valueProperty().addListener(new ChangeListener<Park>() {
            @Override
            public void changed(ObservableValue<? extends Park> observable, Park oldValue, Park newValue) {
                if (newValue != null) {
                    installationList.setItems(FXCollections.observableArrayList(new ArrayList(newValue.getInstallations())));
                } else {
                    installationList.setItems(FXCollections.observableArrayList(new ArrayList()));
                }
                if (parkSelect.getValue() != null) {
                    Park park = (Park) parkSelect.getValue();
                    managerName.setText(park.getManager().getName());
                    managerSalary.setText(park.getManager().getSalary().toString());
                    income.setText(String.format("%.2f лв.", park.getIncome()));
                    
                    int visitorCount = park.getVisitors().size();
                    int visitorsAge = park.getVisitors().stream().mapToInt(v -> v.getAge()).sum();
                    if (visitorCount > 0) {
                        averageAge.setText(String.format("%.2f", (double) visitorsAge / visitorCount));
                    } else {
                        averageAge.setText("0");
                    }
                }
            }
        });
        parkSelect.getSelectionModel().selectFirst();
    }

}
