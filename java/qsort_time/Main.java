import java.util.LinkedList;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.Set;
import java.util.Collection;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LinkedList<time> timeList = new LinkedList<time>();
        int numberOfTimes = scanner.nextInt();
        
        for (int i = 0; i < numberOfTimes; i++) {
            time newTime = new time(scanner.next());
            newTime.addMinutes(scanner.nextInt());
            timeList.add(newTime);
        }
        Collections.sort(timeList);
        for (time timeIterator : timeList) {
            timeIterator.printTime();
        }
        
    }
}

class time implements Comparable<time>{
    public int timeInMinutes = 0;

    public void printTime() {
        System.out.printf("%02d:%02d\n", (timeInMinutes/60)%24, timeInMinutes%60);
    }

    public time(String timeString) {
        String[] hoursAndMinutes = timeString.split("\\:");
        timeInMinutes = Integer.parseInt((hoursAndMinutes[0]))*60 + Integer.parseInt(hoursAndMinutes[1]);
    }

    public void addMinutes(int minutes) {
        timeInMinutes += minutes;
        timeInMinutes %= (60*24);
    }
    
    @Override
    public int compareTo(time time) {
        return Integer.compare(timeInMinutes, time.timeInMinutes);
    }
}