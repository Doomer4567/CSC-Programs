public void main() {
        //Correlation Of Frequency
        char[] CipherText = "ITSTYXYZRGQJTAJWXTRJYMNSLGJMNSIDTZ".toCharArray();
        char[] Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();
        Double[] COF = new Double[26];

        for (int i = 0; i < 26; i++) {
            COF[i] = 0.0;
            for (char c : CipherText) {
                if (Alphabet[i] == c) {
                    COF[i] += 1.0;
                }
            }

            COF[i] /= CipherText.length;
            //T (19)= .147
            //J (9)=.117
            //S(18) & Y(24) = .088
            System.out.println(Alphabet[i] + " = " + COF[i]);
        }
        System.out.println(" ");
        double[] Correlation = new double[26];
        for (int i =1; i < 26; i++){
            Correlation[i] = COF[i] * ((26 + Alphabet[i]-'I') % 26);
            System.out.println(Correlation[i]);
        }
        //1.411764705882353 (25)
        //1.6176470588235294 (20)
        //1.4117647058823528 (5)

        char[] Decrypted= new char[CipherText.length];
        for (int i =0; i < CipherText.length; i++){
            Decrypted[i] =(char) ((CipherText[i] - 'A' - 5 + 26) % 26 + 'A');
        }
        System.out.println(" ");
        System.out.println(Decrypted);
}



