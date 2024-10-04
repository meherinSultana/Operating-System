package readerwriter;

import java.util.concurrent.Semaphore;

public class ReadWrite {

    private Semaphore readLock, writeLock;

    private int rc;

    public ReadWrite() {
        readLock = new Semaphore(1);
        writeLock = new Semaphore(1);
        rc = 0;
    }

    public void read(String readerName) throws InterruptedException {

        readLock.acquire();
        rc++;
        if (rc == 1) {
            writeLock.acquire();
        }
        readLock.release();

        System.out.println(readerName + " Reading");
        Thread.sleep(2000);
        System.out.println(readerName + " Leaving");
        readLock.acquire();
        rc--;

        if (rc == 0) {
            writeLock.release();
        }
        readLock.release();
    }

    public void write(String name) throws InterruptedException {

        writeLock.acquire();
        System.out.println(name + " Writing");
        Thread.sleep(2000);
        System.out.println(name + " Leaving");
        writeLock.release();
    }
}
