/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package amusementparkmanager.views.controllers;

import amusementparkmanager.entities.Installation;
import amusementparkmanager.services.InstallationService;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;

/**
 * FXML Controller class
 *
 * @author Marto
 */
public class InstallationTabController implements Initializable {

    @FXML
    private TableView installationTableView;

    @FXML
    private TableColumn installationColumn;

    @FXML
    private TableColumn minAgeColumn;

    @FXML
    private TextField installationTextField;

    @FXML
    private TextField minAgeTextField;

    @FXML
    private void saveInstallation(ActionEvent event) {
        if ((installationTextField.getText() != null && !installationTextField.getText().isEmpty())
                && (minAgeTextField.getText() != null && !minAgeTextField.getText().isEmpty())) {
            String installationName = installationTextField.getText();
            int minAge = Integer.parseInt(minAgeTextField.getText());

            int installationId = InstallationService.addInstallation(installationName, minAge);
            Installation installation = InstallationService.getInstallation(installationId);

            installationTableView.getItems().add(installation);
            installationTextField.clear();
            minAgeTextField.clear();
        } else {
            // TODO
            System.out.println("You have not entered installation name and/or minimum age!");
        }
    }

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        initViews();
    }

    private void initViews() {
        final ObservableList<Installation> installationList
                = FXCollections.observableArrayList(InstallationService.
                        getInstallations());

        installationColumn.setCellValueFactory(
                new PropertyValueFactory<>("name"));
        minAgeColumn.setCellValueFactory(
                new PropertyValueFactory<>("minAge"));

        installationTableView.setItems(installationList);
    }

}
