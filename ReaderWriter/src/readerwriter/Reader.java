package readerwriter;

public class Reader extends Thread {

    private ReadWrite db;
    private String readerName;

    public Reader(ReadWrite db, String readerName) {
        this.db = db;
        this.readerName = readerName;
    }

    @Override
    public void run() {

        try {
            while (true) {
                db.read(readerName);
                System.out.println(readerName + " is waiting. ");
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
