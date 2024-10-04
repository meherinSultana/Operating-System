package readerwriter;

public class Writer extends Thread {

    private ReadWrite db;
    private String writerName;

    public Writer(ReadWrite db, String writerName) {
        this.db = db;
        this.writerName = writerName;
    }

    @Override
    public void run() {

        try {
            while (true) {

                System.out.println(writerName + " is waiting... ");
                db.write(writerName);
                Thread.sleep(2000);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
