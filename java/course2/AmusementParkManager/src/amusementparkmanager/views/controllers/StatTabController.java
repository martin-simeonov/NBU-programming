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
import java.util.List;
import java.util.ResourceBundle;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;

/**
 * FXML Controller class
 *
 * @author Marto
 */
public class StatTabController implements Initializable {

    @FXML
    private Label income;

    @FXML
    private Label averageAge;

    @FXML
    public void refresh(Event action) {
        initViews();
    }

    private void initViews() {
        List<Park> parks = ParkService.getParks();
        income.setText(String.valueOf(parks.stream().mapToDouble(p -> p.getIncome()).sum()));
        int visitorCount = parks.stream().mapToInt(p -> p.getVisitors().size()).sum();
        int visitorsAge = parks.stream().mapToInt(p -> p.getVisitors().stream().mapToInt(v -> v.getAge()).sum()).sum();
        if (visitorCount > 0) {
            averageAge.setText(String.format("%.2f", (double) visitorsAge / visitorCount));
        } else {
            averageAge.setText("0");
        }
    }

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        initViews();
    }

}
