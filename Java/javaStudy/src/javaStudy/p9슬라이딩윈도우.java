import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//�Է¿�
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));//��¿�
    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        for(int test_case = 1; test_case <= t; test_case++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int sum = 0;
            //���� w �� 5���
            // 5��¥�� ���� ���� �Ŀ� ����� �� �ϰ�, �� ���� ���� ����
            // (�� ���� ���� ������ ������ 4���� �� + ���ο� ���ڸ� �� ��)
            int num[] = new int[n];
            int ans = Integer.MIN_VALUE;
            int index = -1;
            for(int i = 0; i < n; i++)
            {
                num[i] = Integer.parseInt(st.nextToken());
                sum += num[i];
                if(i >= w - 1)
                {
                    if(ans < sum)
                    {
                        ans = sum;
                        index = i;
                    }
                    sum -= num[i - (w - 1)];
                }
            }
            bw.write("#" + test_case + " " + (index - (w - 1)) + " " + index + " " + ans + "\n");
        }
        br.close();
        bw.close(); 
    }
}