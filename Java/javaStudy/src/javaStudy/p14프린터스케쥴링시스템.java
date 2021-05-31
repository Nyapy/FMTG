import java.io.*;
import java.util.*;


class Printer implements Comparable<Printer>
{
    //en : ������ ����� �Ϸ�Ǵ� �ð�
    //ind : ������ ��ȣ
    long en;
    int ind;
    Printer(long en, int ind)
    {
        this.en = en;
        this.ind = ind;
    }
    @Override
    public int compareTo(Printer o) {
        //����� ���� �Ϸ�Ǵ� ��
        if(en < o.en) return -1;
        if(en > o.en) return 1;
        //������ ��ȣ�� ���� ��
        if(ind < o.ind) return -1;
        if(ind > o.ind) return 1;
        return 0;
    }

}

class Doc implements Comparable<Doc>
{
    //s : ����� ��û�� �ð�
    //cost : �ش� ������ ����ϴµ� �ʿ��� �ð�
    //ind : ���� ��ȣ(sort�� ������ ���̹Ƿ� ���� ��ȣ�� ����ؾ� ��)
    long s;
    long cost;
    int ind;
    Doc(long s, long cost, int ind)
    {
        this.s = s;
        this.cost = cost;
        this.ind = ind;
    }
    @Override
    public int compareTo(Doc right) {
        // ��� ��û�� ���� ��
        if(s < right.s) return -1;
        if(s > right.s) return 1;
        if(cost < right.cost) return -1;
        if(cost > right.cost) return 1;
        // ���� ��ȣ�� ���� ��
        if(ind < right.ind) return -1;
        if(ind > right.ind) return 1;
        return 0;
    }
}

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        //�Է� ó��
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        //doc : �� ����(�����Ͽ� ���̿� �˴ϴ�.)
        Doc[] doc = new Doc[n];
        //doc_print : �� ������ ��µ� ������ ��ȣ
        int[] doc_print = new int[n];

        //���� �Է�
        for(int i = 0; i < n; i++)
        {
            st = new StringTokenizer(br.readLine());
            long s = Long.parseLong(st.nextToken());
            long cost = Long.parseLong(st.nextToken());
            doc[i] = new Doc(s, cost, i);
        }

        //����� ��û�� ������� ������ ����
        Arrays.sort(doc);//NlogN

        //����� ���� �Ϸ�� �����͸� ã�� ���� PriorityQueue ����
        PriorityQueue<Printer> pq = new PriorityQueue<>();
        for(int i = 1; i <= m; i++)
        {
            pq.add(new Printer((long)0, i));//MlogM
        }

        //��û�� ���� �������� Ȯ���Ͽ� ������ ����
        //�����Ǵ� �����ʹ� ����� ���� �Ϸ�Ǵ� �����ͷ�
        long ans = 0;
        for(int i = 0; i < n; i++)
        {
            //now : ����� ���� ���� �Ϸ�Ǵ� ������
            Printer now = pq.poll();//NlogM
            long now_en = now.en;

            if(now.en <= doc[i].s)
            //���� ������� ������ �Ϸ�� ���� �̹� ������ ��� ��û�� ���� ���
            {
                //��¿�û ���ĺ��� �ð� ���
                ans += doc[i].cost;
                now_en = doc[i].s + doc[i].cost;
            }
            else
            //���� ������� ������ �Ϸ�Ǳ� ������ �̹� ������ ��� ��û�� ���� ���
            {
                //���� ������� ������ �Ϸ�� ���ĺ��� �ð� ���
                ans += (now.en - doc[i].s) + doc[i].cost;
                now_en = now.en + doc[i].cost;
            }
            //�ش� �����ʹ� ���Ŀ� �� �� �� �����Ƿ� PriorityQueue�� ���� ���
            pq.add(new Printer(now_en, now.ind));//NlogM
            //�̹� ������ ����� ������ ��ȣ�� ���
            doc_print[doc[i].ind] = now.ind;
        }

        //�� ������ ��ϵ� ������ ��ȣ�� ���
        for(int i = 0; i < n; i++)
        {
            bw.write(doc_print[i] + "\n");
        }
        bw.close();
        br.close();
    }
}