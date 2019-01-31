/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package amusementparkmanager.views.controllers;

import amusementparkmanager.entities.Installation;
import amusementparkmanager.entities.Manager;
import amusementparkmanager.services.InstallationService;
import amusementparkmanager.services.ManagerService;
import amusementparkmanager.services.ParkService;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;

/**
 * FXML Controller class
 *
 * @author Marto
 */
public class AmusementParkCreateController implements Initializable {
    
    @FXML
    private TextField parkName;
    
    @FXML
    private TextField saleThreshold;
    
    @FXML
    private TextField salaryIncrease;
    
    @FXML
    private TableView installationTableView;
    
    @FXML
    private TableColumn installationColumn;
    
    @FXML
    private ComboBox selectInstallation;
    
    @FXML
    private ComboBox selectManager;
    
    @FXML
    private TextField ticketPrice;
    
    @FXML
    public void addInstallation(Event action) {
        if (selectInstallation != null && selectInstallation.getValue() != null) {
            Installation installation = (Installation) selectInstallation.getValue();
            installationTableView.getItems().add(installation);
        } else {
            // TODO
            System.out.println("more info needed");
        }
    }
    
    @FXML
    public void addManager(Event action) {
        Parent root;
        try {
            root = FXMLLoader.load(getClass().getClassLoader().getResource("amusementparkmanager/views/AddManager.fxml"));
            Stage stage = new Stage();
            stage.setTitle("Добави мениджър");
            stage.setScene(new Scene(root, 380, 200));
            stage.show();
            stage.setOnHiding((WindowEvent) -> {
                // Refresh managers list on closing add manger window
                selectManager.setItems(ManagerService.getAvailableManagers());
                selectManager.getSelectionModel().selectLast();
            });
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public void savePark(Event action) {
        if (parkName == null || parkName.getText().isEmpty()) {
            // TODO
            System.out.println("Empty name");
            return;
        }
        if (selectManager == null || selectManager.getValue() == null) {
            // TODO
            System.out.println("Empty manager");
            return;
        }
        if (saleThreshold == null || saleThreshold.getText().isEmpty()) {
            // TODO
            System.out.println("Empty salary threshold");
            return;
        }
        if (salaryIncrease == null || salaryIncrease.getText().isEmpty()) {
            // TODO
            System.out.println("Empty salary increase");
            return;
        }
        if (installationTableView == null || installationTableView.getItems().isEmpty()) {
            // TODO
            System.out.println("Empty installations");
            return;
        }
        if (ticketPrice == null || ticketPrice.getText().isEmpty()) {
            // TODO
            System.out.println("Empty ticket price");
            return;
        }
        
        // Save park to database
        ParkService.addPark(parkName.getText(), (Manager) selectManager.getSelectionModel().getSelectedItem(),
                Double.valueOf(saleThreshold.getText()), Integer.valueOf(salaryIncrease.getText()),
                Double.valueOf(ticketPrice.getText()), installationTableView.getItems());
        
        // Close window
        Button btn = (Button) action.getSource();
        ((Stage) btn.getScene().getWindow()).close();
    }
    
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        final ObservableList<Installation> installationList = 
                FXCollections.observableArrayList(InstallationService.
                                                    getInstallations());
        selectInstallation.setItems(installationList);
        
        // Initialize installation table
        installationColumn.setCellValueFactory(
                new PropertyValueFactory<>("name"));
        
        // Initialize manager list
        selectManager.setItems(ManagerService.getAvailableManagers());
        selectManager.getSelectionModel().selectFirst();
    }    
    
}
