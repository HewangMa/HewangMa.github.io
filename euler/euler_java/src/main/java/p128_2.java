import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class edge {
    List<Long> cells;
    int length;
    Long start;

    edge(Long start, int length) {
        this.length = length;
        this.start = start;
        cells = new ArrayList<>();
        for (int i = 0; i <= length; i++) cells.add(start + i);
    }


    public void set(int idx, Long item) {
        cells.set(idx, item);
    }

    public int size() {
        return cells.size();
    }
}

class hexa {
    edge[] edges;
    Long start;
    int length;

    hexa(Long start, int length) {
        this.length = length;
        this.start = start;
        edges = new edge[6];
        for (int i = 0; i < 6; i++)
            edges[i] = new edge(start + i * length, length);
        edges[5].set(edges[5].size() - 1, start);
    }

}

public class p128_2 {

    private static boolean prime(Long n) {
        if (n <= 1) return false;
        for (long i = 2L; i <= Math.sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }

    public static List<Long> cal_tiles(hexa h1, hexa h2, hexa h3) {
        List<Long> tiles = new ArrayList<>();
        int length = h2.length;
        for (int i = 0; i < 6; i++) {
            // for every edge
            for (int j = 0; j <= length - 1; j++) {
                // for every number on the edge
                Long t = h2.edges[i].cells.get(j);
                List<Long> neighbors = new ArrayList<>();
                if (j == 0) {
                    neighbors.add(h3.edges[i].cells.get(j));
                    neighbors.add(h3.edges[i].cells.get(j + 1));
                    neighbors.add(h2.edges[i].cells.get(j + 1));
                    neighbors.add(h1.edges[i].cells.get(j));
                    neighbors.add(h2.edges[(i + 5) % 6].cells.get(length - 1));
                    neighbors.add(h3.edges[(i + 5) % 6].cells.get(length));
                } else {
                    neighbors.add(h3.edges[i].cells.get(j));
                    neighbors.add(h3.edges[i].cells.get(j + 1));
                    neighbors.add(h2.edges[i].cells.get(j + 1));
                    neighbors.add(h1.edges[i].cells.get(j));
                    neighbors.add(h1.edges[i].cells.get(j - 1));
                    neighbors.add(h2.edges[i].cells.get(j - 1));
                }
                int cnt = 0;
                for (Long n : neighbors)
                    if (prime(Math.abs(t - n))) cnt++;
                if (cnt >= 3) tiles.add(t);
            }
        }
        return tiles;
    }

    public static void main(String[] args) {
        long start = 2L;
        int length = 1;
        hexa h1 = new hexa(start, length);
        start += length * 6;
        length++;
        hexa h2 = new hexa(start, length);
        List<Long> all_tiles = new ArrayList<>();
        all_tiles.add(1l);
        all_tiles.add(2l);
        while (true) {
            start += length * 6;
            length++;
            hexa h3 = new hexa(start, length);
            List<Long> tiles = cal_tiles(h1, h2, h3);
            all_tiles.addAll(tiles);
            h1 = h2;
            h2 = h3;
            if (h3.length % 5001 == 0)
                System.out.println("when the hexa.length is " + h3.length + ", get " + all_tiles.size() + " tiles");
            if (all_tiles.size() >= 2014) break;
        }
        Collections.sort(all_tiles);
        System.out.print("all_tiles.size(): ");
        System.out.println(all_tiles.size());
        System.out.println(all_tiles.get(1999));
    }
}
