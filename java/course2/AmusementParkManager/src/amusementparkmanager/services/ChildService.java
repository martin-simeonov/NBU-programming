/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package amusementparkmanager.services;

import amusementparkmanager.entities.Child;
import amusementparkmanager.entities.Manager;
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
public class ChildService {
    private static SessionFactory sessionFactory = HibernateUtil.getSessionFactory();

    public static ObservableList<Child> getChildren() {
        Session session = sessionFactory.openSession();
        Transaction tx = null;

        try {
            tx = session.beginTransaction();
            List children = session.createQuery("FROM Child").list();
            ObservableList<Child> childList = FXCollections.observableArrayList(children);
            tx.commit();
            return childList;
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
    
    public static int addChild(String name, int age) {
        Session session = sessionFactory.openSession();
        Transaction tx = null;
        Integer childId = null;

        try {
            tx = session.beginTransaction();
            Child child = new Child(name, age);
            childId = (Integer) session.save(child);
            tx.commit();
        } catch (HibernateException e) {
            if (tx != null) {
                tx.rollback();
            }
            e.printStackTrace();
        } finally {
            session.close();
        }
        return childId;
    }
}
