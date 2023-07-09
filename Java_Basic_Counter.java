class Java_Basic_Counter {
    public static void main(String[] args) {
        String s = "kjewfgyug 1232.35346635748 1111111111111111111111111111111111111111111111111.2222222222222222222222222222222 11111111111111111112345678999999999999999999";
        String[] w = s.split(" ");
        int f = 0, i = 0, c = 0;
        for (String x : w) {
            if (x.matches("^[0-9]*"))
                i++;
            else if (x.matches("^[0-9]*.[0-9]*$"))
                f++;
            else if (x.matches("^[a-z]*"))
                c += 1;
        }
        System.out.println("float : " + f);
        System.out.println("Int : " + i);
        System.out.println("strings : " + c);
    }
}