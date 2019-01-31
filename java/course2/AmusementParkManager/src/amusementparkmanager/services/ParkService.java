/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package amusementparkmanager.services;

import amusementparkmanager.entities.Installation;
import amusementparkmanager.entities.Manager;
import amusementparkmanager.entities.Park;
import java.util.HashSet;
import java.util.List;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;

/**
 *
 * @author Marto
 */
public class ParkService {
    
    private static SessionFactory sessionFactory = HibernateUtil.getSessionFactory();

    public static Integer addPark(String name, Manager manager, Double saleThreshold,
                                Integer salaryIncrease, Double ticketPrice,
                                List<Installation> installations) {
        Session session = sessionFactory.openSession();
        Transaction tx = null;
        Integer id = null;

        try {
            tx = session.beginTransaction();
            Park  park = new Park(manager, name, saleThreshold, salaryIncrease, 
                    ticketPrice, new HashSet<>(installations));
            id = (Integer) session.save(park);
            tx.commit();
        } catch (HibernateException e) {
            if (tx != null) {
                tx.rollback();
            }
            e.printStackTrace();
        } finally {
            session.close();
        }
        return id;
    }
    
    public static ObservableList<Park> getParks() {
        Session session = sessionFactory.openSession();
        Transaction tx = null;

        try {
            tx = session.beginTransaction();
            List parks = session.createQuery("FROM Park").list();
            ObservableList<Park> parksList = FXCollections.observableArrayList(parks);
            tx.commit();
            return parksList;
        } catch (HibernateException e) {
            if (tx != null) {
                tx.rollback();
            }
            e.printStackTrace();
        } finally {
            session.close();
        }
        return null;
    }
    
    /* Method to UPDATE park */
    public static void update(Park park) {
        Session session = sessionFactory.openSession();
        Transaction tx = null;

        try {
            tx = session.beginTransaction();
            session.update(park);
            tx.commit();
        } catch (HibernateException e) {
            if (tx != null) {
                tx.rollback();
            }
            e.printStackTrace();
        } finally {
            session.close();
        }
    }
    
}
