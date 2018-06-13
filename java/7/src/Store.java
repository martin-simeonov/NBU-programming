import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Store {
	private Goods goods;
	private int goodsCount;
	private Company owner;
	private List<Company> clients;
	private List<Invoice> invoices;
	
	private static int invoiceCount = 0;
	
	public Store(Goods goods, int goodsCount, Company owner, List<Company> clients) {
		this.goods = goods;
		this.goodsCount = goodsCount;
		this.owner = owner;
		this.clients = clients;
		invoices = new ArrayList<>();
	}
	
	public Store() {
		this(new Goods(), 0, new Company(), new ArrayList<Company>());
	}
	
	public void goodsDelivery(int amount) {
		goodsCount += amount;
	}
	
	public Invoice sellGoods(int amount, Company recipient) throws InsufficientQuantityOfGoodsException {
		if ((goodsCount - amount) < 0) {
			throw new InsufficientQuantityOfGoodsException(goods);
		} else {
			goodsCount -= amount;
			clients.add(recipient);
			return createInvoice(recipient, amount);
		}
	}
	
	private Invoice createInvoice(Company recipient, int amount) {
		Invoice invoice = new Invoice(++invoiceCount, owner, recipient, new Date().toString(), goods, amount);
		invoices.add(invoice);
		return invoice;
	}
	
	public String writeInvoiceToFile(Invoice invoice) {
		FileOutputStream file;
		ObjectOutputStream oos;
		String filename = "invoice" + invoice.getNumber() + ".ser";
		try {
			file = new FileOutputStream(filename);
			oos = new ObjectOutputStream(file);
			oos.writeObject(invoice);

			file.close();
			oos.close();
		} catch (FileNotFoundException e) {
			System.out.println("Cannot open file");
		} catch (IOException e) {
			e.printStackTrace();
		}
		return filename;
	}
	
	public String writeInvoiceToFile() {
		return writeInvoiceToFile(invoices.get(invoices.size() - 1));
	}
	
	public Invoice readInvoiceFromFile(String filename) {
		FileInputStream file;
		ObjectInputStream ois;
		Invoice invoice = null;
		try {
			file = new FileInputStream(filename);
			ois = new ObjectInputStream(file);
			invoice = (Invoice) ois.readObject();

			file.close();
			ois.close();
		} catch (FileNotFoundException e) {
			System.out.println("Cannot open file");
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		if (invoice != null)
			invoice.print();
		
		return invoice;
	}
}
