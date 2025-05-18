public class Vigenere {
    public static void main(String[] args) {
        char[] CipherText = "UPRCW IHSGY OXQJR IMXTW AXVEB DREGJ AFNIS EECAG SSBZR TVEZU RJCXT OGPCY OOACS EDBGF ZIFUB KVMZU FXCAD CAXGS FVNKM SGOCG FIOWN KSXTS ZNVIZ HUVME DSEZU LFMBL PIXWR MSPUS FJCCA IRMSR FINCZ CXSNI BXAHE LGXZC BESFG HLFIV ESYWO RPGBD SXUAR JUSAR GYWRS GSRZP MDNIH WAPRK HIDHU ZBKEQ NETEX ZGFUI FVRI".toCharArray();
        char[] Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();

        int keylength = 0;
        int Group = 0;
        double avgIC = 0.0;
        double TotalIC = 0.0;
        for (keylength = 0; keylength <= 10; keylength++) {
            for (int i = 0; i < keylength; i++) {
                StringBuilder segmentedText = new StringBuilder();
                for (int j = i; j < CipherText.length; j += keylength) {
                    segmentedText.append(CipherText[j]);
                }
                if (segmentedText.length() > 1) {
                    TotalIC += calculateIC(segmentedText.toString(), Alphabet);
                    Group++;
                }
            }
        }
        avgIC = Group > 0 ? TotalIC / Group : 0.0;
        System.out.printf("Key Length %d: IC = %.5f\n", keylength, avgIC);

        char[] text = new char[keylength];
        for (int i = 0; i < keylength; i++) {
            text[i] = CipherText[i];
        }

        char[] key = CeaserCipher(text,Alphabet);

        System.out.println(decryption(CipherText,key));

    }

    public static char[] CeaserCipher(char[] CipherText, char[] Alphabet){
        Double[] COF = new Double[26];

        for (int i = 0; i < 26; i++) {
            COF[i] = 0.0;
            for (char c : CipherText) {
                if (Alphabet[i] == c) {
                    COF[i] += 1.0;
                }
            }

            COF[i] /= CipherText.length;
            System.out.println(Alphabet[i] + " = " + COF[i]);
        }
        System.out.println(" ");
        double[] Correlation = new double[26];
        for (int i =1; i < 26; i++){
            Correlation[i] = COF[i] * ((26 + Alphabet[i]-'I') % 26);
            System.out.println(Correlation[i]);
        }


        char[] Decrypted= new char[CipherText.length];
        for (int i =0; i < CipherText.length; i++){
            Decrypted[i] =(char) ((CipherText[i] - 'A' - 5 + 26) % 26 + 'A');
        }
        System.out.println(" ");
        System.out.println(Decrypted);
        return Decrypted;
    }

    public static char[] decryption(char[] CipherText, char[] key){
        char[] Decrypted = new char[CipherText.length];
        int keylen = key.length;
        for (int i = 0; i < CipherText.length; i++) {
            char cipherChar = CipherText[i];
            char keyChar = key[i % keylen];
            int shift = keyChar - 'A';

            char Decryptchar = (char) ('A' + (cipherChar - 'A' - shift + 26) % 26);
            Decrypted[i] = Decryptchar;

        }
        return Decrypted;
    }


    public static double calculateIC(String text, char[] Alphabet) {
        char[] Text = text.toCharArray();
        double[] Freq = new double[26];
        for (int i = 0; i < 26; i++) {
            Freq[i] = 0.0;
            for (char c : Text) {
                if (Alphabet[i] == c) {
                    Freq[i] += 1.0;
                }
            }
            System.out.println(Alphabet[i] + " = " + Freq[i]);
        }


        {
            double IC = 0.0;
            for (int i = 0; i < 26; i++) {
                IC += Freq[i] * (Freq[i] - 1);
            }
            IC /= (Text.length * (Text.length - 1));
            System.out.println(" ");
            return IC;
        }
    }
}