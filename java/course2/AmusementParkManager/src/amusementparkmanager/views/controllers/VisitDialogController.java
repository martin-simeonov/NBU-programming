/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package amusementparkmanager.views.controllers;

import amusementparkmanager.entities.Child;
import amusementparkmanager.entities.Park;
import amusementparkmanager.services.ParkService;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;

/**
 * FXML Controller class
 *
 * @author Marto
 */
public class VisitDialogController implements Initializable {

    @FXML
    private Label visitInfo;

    @FXML
    private Label visitInfoInstallations;

    @FXML
    private ListView installationList;

    private Child visitor;
    private Park park;

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // Sale is not possible
        if (!park.makeSale(visitor)) {
            visitInfo.setText(visitor.getName() + " неможе да посети нито едно съоръжение в "
                    + park.getName());
            visitInfoInstallations.setText("Закупуването на билет е неуспешно");
            installationList.setVisible(false);
        } else {
            // Sale is possible load list of available installations for this visitor
            visitInfo.setText(visitor.getName() + " успешно закупи билет за " + park.getName());
            installationList.setItems(FXCollections.observableArrayList(park.getAccessibleInstallations(visitor)));

            // UPDATE in database
            ParkService.update(park);
        }
    }

    void initData(Park park, Child visitor) {
        this.park = park;
        this.visitor = visitor;
    }
}
