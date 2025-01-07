# Programmazione ad Oggetti


Paradigmi: Funzionale e Imperativo


'Paradigma ad oggetti' si basa più sulla parte di progettazione infatti principalmente sarà imperativo il paradigma vero e proprio


Progettazione di sistemi funzione interfacce e possibilità di sostituibilità, classi/componenti con comportamenti intercambiabili


Libro: Concetti di informatica e fondamenti di Java


Sito Moodle a chiave libera : CT0372


### Esame:


- 3 Domande teoriche * 4 punti = 12 punti
- Esercizio programma Java 20 punti (possibile utilizzo di testo e appunti)
- Consegna solo bella copia


## Cos'è un oggetto?


Un oggetto è un entità che permette di compiere **azioni** su di esso e possiede uno **stato** interno 
Es Contatore irrigazione: **Azioni:** Introduzione acqua, lettura litri, reset lettura .**Stato:** numero litri contato


**Interfaccia:** insieme di capacità che il sistema espone	 es. interfaccia USB ha determinate specifiche standard


Qualsiasi oggetto che onora un interfaccia uguale ad un altro oggetto allora essi sono sostituibili


Classe è una specifica formale


Le interfacce permettono la compatibilità tra classi e non contengono variabili


```java
public class MainClass{
	public static void main(String[] args){
        System.out.println("Bellaaaaaaaaaaaaaaaa");
    }
}
```


```java
public class Rectangle{
    double h, b;
    Rectangle(double h, double b){
        this.h = h; this.b = b;
    }
    public double computeArea(){
        return h*b;
    }
}
```


**Usare la classe Main solo per il metodoi main le dipendenze in metodi e attributi inseriscile in altre classi specializzate**  


## SintassiName


```java
public class NameClassStartCapitalLetter{
    public void nameMethodStartLowercaseLetter(){
        //code
    }
}
```


## Compilazione


Il file sorgente .java viene compilato dal compilatore java che lo trasforma in un file .class binario 


Il file compilato .class è interpretato da una virtual machine che lo trasforma in codice compatibile con vari sistemi operativi o ambienti di sviluppo


## Chiamata per esecuzione


Essa può essere fatta anche dall'alto'


```cmd
C:\Users\Enrico\IdeaProjects\TutorialJava\src\com\company>cd ..


C:\Users\Enrico\IdeaProjects\TutorialJava\src\com>cd ..


C:\Users\Enrico\IdeaProjects\TutorialJava\src>java com.company.Main
Hello Word


```


# Types


## Variables and Constants


```java
public class Main {
    public static void main(String[] args) {
        int age = 30, newAge = 50;
        System.out.println("Stringify -> "+age+newAge);
        System.out.println(age+newAge+" <- notStringify ");
    }
}


```






## Primitive and Reference Types


### Primitive


|  Type   | Bytes |     Range     |
| :-----: | :---: | :-----------: |
|  byte   |   1   |  [-128, 127]  |
|  short  |   2   | [-2^15, 2^15‬] |
|   int   |   4   | [2^31, -2^31] |
|  long   |   8   |               |
|  float  |   4   |               |
| double  |   8   |               |
|  char   |   2   |    A, B, C    |
| boolean |   1   | true / false  |


```java
byte age = 30;
int viewsBigNumber = 321_234;	//_ permette di leggere meglio il numero 
int viewsBadBigNumber = 321234;
long viewsCount = 3_123_456_789L;//serve la L per indicargli il tipo long
long viewsBad = 3123456789L;
float price = 10.99F;			//serve la F per indicargli il tipo float
boolean bool = true;
```


### Reference


```java
import java.util.Date;
public class Main {
    public static void main(String[] args) {
        Date now = new Date();
        now.getTime();
        System.out.println(now);
    }
}


```


Due diversi puntatori che fanno riferimento allo stesso RValue (perchè alloco solo point1)


```java
import java.awt.*;
public class Main {
    public static void main(String[] args) {
        Point point1 = new Point(1,1);
        Point point2 = point1;
        point1.x = 2;
        System.out.println(point2);//java.awt.Point[x=2,y=1]
    }
}
```


Anche se le stringhe non sono tipo primitive non vanno allocarle con new


```java
String message = "Bellaaa"+"aaaaaa";
System.out.println(message.endsWith("aaa"));    //true
System.out.println(message.startsWith("Bea"));  //false
System.out.println(message.length());           //13
System.out.println(message.indexOf("el"));      //1
System.out.println(message.indexOf("Ciao"));    //-1 Perchè non c'è
System.out.println(message.replace("a", ""));   //Bell (è una nuova stringa, message è invariata)
System.out.println(message.toLowerCase());		//bellaaaaaaaaa
System.out.println(message.toUpperCase());		//BELLAAAAAAAAA
System.out.println(message);				   //Bellaaaaaaaaa perchè i metodi non la modificano
System.out.println("  Ciao  :)".trim());  		//Ciao  :) toglie spazi iniziali
```


Escape sequence: tab, a capo e \


```java
String message = "C:\t\\Windos\\...\n \"Enrico\"";
System.out.println(message);
//C:	\Windos\...
// "Enrico"
```


### Arrays


```java
int[] numbers = new int[5];
numbers[0] = 1;
System.out.println(numbers);	//[I@6acbcfc0 che è la cella di memoria
```


```java
import java.util.Arrays;
public class Main {
    public static void main(String[] args) {
        float[] arr = new float[2];
        arr[0] = 1;
        System.out.println(Arrays.toString(arr));						//[1.0, 0.0]
        int[] numbers = {4, 2, 3, 8};
        System.out.println(numbers.length+" : "+Arrays.toString(numbers));//4 : [4, 2, 3, 8]
        Arrays.sort(numbers);
        System.out.println((Arrays.toString(numbers))); 				//[2, 3, 4, 8]
    }
}
```


### Multi-dimensional array


```java
int[][] matrix = new int[2][3];
matrix[0][0] = 1;
System.out.println(Arrays.toString(matrix));		//[[I@6acbcfc0, [I@5f184fc6]
System.out.println(Arrays.deepToString(matrix));	//[[1, 0, 0], [0, 0, 0]]
int[][][] bigMatrix = {{{1,2,3},{4,5}},{{3,2,4},{6,7}}};
System.out.println(Arrays.deepToString(bigMatrix));	//[[[1, 2, 3], [4, 5]], [[3, 2, 4], [6, 7]]]
```


### Constants


Si scrivono tutte in maiuscolo di norma e se modificate il programma non compila


```java
final float PI = 3.14F;	//'final' to unmodifiable variables and use MAIUSC name
```


## Casting


```java
double result = (double)10/(double)3;
System.out.println(result);	//3.3333333333333335
int y = (int)++result;
y = (int)result++;
System.out.println(result);	//5.333333333333334
System.out.println(y);       //4
```


```java
String x = "1";
int y = Integer.parseInt(x) + 2;	//3
String a = "1.1";
double b = Double.parseDouble(x) + 2;//3.1


```






### Implicit casting


byte	>	short	>	int	>	long


```java
short x = 1;
int y = x + 2; //3
```






## Shortcod


```java
int x = 1;
x += 4;	//5
x -= 2;	//3
x *= 2;	//6
x /= 2;	//3
```


Maiusc + F6 su una variabile per fare il rename


## Order of operations


```java
int x = (1+2)*2-4;//2	()		<-		*/		<-		+-
```


## Math & Random


```java
int arrotonda = Math.round(1.1F); 	//1		Arrotonda
double ecesso = Math.ceil(1.1F);    //2.0	Arrotonda per ecesso
double difetto = Math.floor(1.1F);	//1.0	Arrotonda per difetto
int maggiore = Math.max(1,2);   	//2
int minore = Math.min(1,2); 		//1
```


```java
double random = Math.random();						//Numerorandom tra 0 e 1
int randomTo100 =(int) Math.round(Math.random()*100); //Numerorandom tra 1 e 100
int randomTo100 =(int) (Math.random()*100); 		 //Numerorandom tra 1 e 100
Random rnd = new Random();							//Possibile seed tra le parentesi del costruttore
int nest = rnd.nextInt(100); 						//Numeri tra 0(Incluso) e 100 Escluso
```


### Formatting Numbers


Errore è un abstract non puoi creare un istanza della classe


```java
import java.text.NumberFormat;
NumberFormat currency = new NumberFormat();
```


Si può fare a step o tutto insieme l'accesso ai sottometodi:


```java
import java.text.NumberFormat;
NumberFormat currency = NumberFormat.getCurrencyInstance();
String percent = NumberFormat.getPercentInstance().format(0.12);	//%12
String result = currency.format(1234567.891);					  //1.234.567,89 €
```


## Input


Read from **terminal**


```java
import java.util.Scanner; 
Scanner scanner = new Scanner(System.in);   //Scannerizza (Dal terminale)
System.out.print("Name and Surname? ");
String nameAndSurname = scanner.nextLine();	//scanner.nextLine().trim() Per togliere gli spazi prima
System.out.print("Age? ");
byte age = scanner.nextByte();
System.out.print("Height? ");
float height = scanner.nextFloat();
/*System.out.print("Name? ");	Prende solo una strinda limitato dallo spazio
 String name = scanner.next();*/
(nameAndSurname+" you are "+age+" and height: "+height);//Enrico Baldasso you are 20 and height: 1.82


```


### Mutuo


Quando fai un programma non lasciare numeri o variabili 'incognite' e dichiara prima le costanti usate


```java
import java.util.Scanner;
import java.text.NumberFormat;
public class Main {
    public static void main(String[] args) {
        final byte MONTHS_IN_YEAR = 12;
        final byte PERCENT = 100;


        Scanner scanner = new Scanner(System.in);   //Scannerizza (Dal terminale)
        System.out.print("Capitale: ");
        long principal = scanner.nextLong();
        System.out.print("Interesse annuo: ");
        float interestRateAnnual = scanner.nextFloat();
        System.out.print("Durata in anni: ");
        int years = scanner.nextInt();
        float monthlyInterest = interestRateAnnual/(PERCENT*MONTHS_IN_YEAR);  //Monthly rate without percentage
        int numberOfPayments = years*MONTHS_IN_YEAR;              //Total payments
        double morgage = principal*(monthlyInterest*Math.pow(1+monthlyInterest, numberOfPayments))
                        / (Math.pow(1+monthlyInterest, numberOfPayments)-1);
        NumberFormat formatting = NumberFormat.getCurrencyInstance();
        System.out.println("Mutuo: "+formatting.format(morgage));


    }
}


```


### Switch


```java
switch (var) {
    case 1:
        System.out.println("Ciao");
        break;
    case 2:
        System.out.println("Bella");
        break;
    default:
        System.out.println("Nulla");
}
```


### For


```java
public static void main(String[] args) {
    String[] fruits = { "Apple", "Mango", "Orange"};


    for(int i = 0; i<fruits.length; i++)
        System.out.println(fruits[i]);
	/*	==	*/
    for (String var : fruits)
        System.out.println(var);


}
```


### quit


```java
Scanner scanner = new Scanner(System.in);
String input = "";
while (!input.equals("quit")) {
    System.out.print("Input: ");
    input = scanner.next().toLowerCase();
}
```


## Classes & Object


```java
String studentMajor = " ComputerScience"
```


# Graphics 2D


Referenza codice:  http://www.newthinktank.com/2012/06/java-video-tutorial-47/ 


## Librerie


```java
import javax.swing.JComponent;  //Components
import javax.swing.JFrame;      //Cornice
import java.awt.*;              //interface
import java.awt.geom.*;         //2D
```


## Compatibilità


```java
/*
    Perchè non si può assegnare un numero seriale a più classi quindi per
    compatibilità tolgo il Warning
 */
@SuppressWarnings("Serial")
```


## Class


```java
package com.company;
import javax.swing.JComponent;  //Components
import javax.swing.JFrame;      //Cornice
import java.awt.*;              //interface
import java.awt.geom.*;         //2D


public class Grafic extends JFrame{


    public static void main(String[] args){
        new Grafic();
    }


    public Grafic(){
        this.setSize(700, 500);
        this.setTitle("Guida grafica");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.add(new DrawStuff(), BorderLayout.CENTER);
        this.setVisible(true);
    }


    private class DrawStuff extends JComponent{


        //Graphics g : Proprietà per disegnare della class JFrame
        public void paint(Graphics g){


            Graphics2D graph2 = (Graphics2D)g;//inizzializzo bidimensionale
           
            graph2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                    RenderingHints.VALUE_ANTIALIAS_ON);
        }
    }
}
```


### Linee & Curve


```java
package com.company;
import javax.swing.JComponent;  //Components
import javax.swing.JFrame;      //Cornice
import java.awt.*;              //interface
import java.awt.geom.*;         //2D


public class Grafic extends JFrame{


    public static void main(String[] args){
        new Grafic();
    }


    public Grafic(){
        this.setSize(700, 500);
        this.setTitle("Guida grafica");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.add(new DrawStuff(), BorderLayout.CENTER);
        this.setVisible(true);
    }


    private class DrawStuff extends JComponent{


        //Graphics g : Proprietà per disegnare della class JFrame
        public void paint(Graphics g){


            Graphics2D graph2 = (Graphics2D)g;//inizzializzo bidimensionale
            graph2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                    RenderingHints.VALUE_ANTIALIAS_ON);


                                            //xA, yA, xB, yB
            Shape drawLine = new Line2D.Float(20, 20, 50, 50);


            Shape drawArc2D0 = new Arc2D.Double(5, 150, 100, 100, 45, 180, Arc2D.OPEN);
            graph2.setPaint(Color.BLUE);


            graph2.draw(drawLine);
            graph2.draw(drawArc2D0);


            Shape drawArc2D1 = new Arc2D.Double(5, 200, 100, 100, 45, 45, Arc2D.CHORD);
            graph2.setPaint(Color.GREEN);
            graph2.draw(drawArc2D1);
            Shape drawArc2D2 = new Arc2D.Double(5, 250, 100, 100, 45, 45, Arc2D.PIE);
            graph2.setPaint(Color.RED);
            graph2.draw(drawArc2D2);
        }
    }
}
```


### Ellissi & Angoli arrotondati


```java
private class DrawStuff extends JComponent{


    //Graphics g : Proprietà per disegnare della class JFrame
    public void paint(Graphics g){


        Graphics2D graph2 = (Graphics2D)g;//inizzializzo bidimensionale
        graph2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                                RenderingHints.VALUE_ANTIALIAS_ON);




        Shape drawEllipse = new Ellipse2D.Float(10,10,100,100);
        Shape drawRoundRec = new RoundRectangle2D.Double(25, 25, 50, 50, 45, 45);
        graph2.setColor(Color.GREEN);
        graph2.draw(drawEllipse);
        graph2.setColor(Color.BLUE);
        graph2.draw(drawRoundRec);


    }
}
```


### Rettangoli e Curve


```java
Shape drawRect = new Rectangle2D.Float(300, 300, 150, 100);
graph2.setColor(Color.YELLOW);
graph2.fill(drawRect);//Riempimento Colore
graph2.setColor(Color.RED);
graph2.draw(drawRect);
Shape drawTransRect = new Rectangle2D.Double(300, 300, 75, 50);
graph2.setColor(Color.BLUE);
graph2.draw(drawTransRect);
Shape drawQuadCurve = new QuadCurve2D.Float(300, 100, 400, 200, 150, 300);
graph2.setColor(Color.GREEN);
graph2.draw(drawQuadCurve);
```


### Trasparenza


```java
graph2.setColor(Color.RED);
//transparenza al 60%
graph2.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 0.40F));
graph2.fill(new Rectangle2D.Float(10,10,150,100));
graph2.fill(new Rectangle2D.Float(20,20,150,100));
//transparenza al 0%
graph2.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 1.00F));
graph2.fill(new Rectangle2D.Float(200,200,50,10));
```


### Gradiente & Custom Color


```java
//Dall'alto verso il basso
GradientPaint theGradient = new GradientPaint(0, 0, Color.BLUE, 0, 60, new Color(0x66ffff));
graph2.setPaint(theGradient);
graph2.fill(new Rectangle2D.Float(10,10,150,100));
//Da sx verso dx
GradientPaint theGradient2 = new GradientPaint(160, 160, Color.BLUE, 220, 160, new Color(0x66ffff));
graph2.setPaint(theGradient2);
graph2.fill(new Rectangle2D.Float(160,160,150,100));
//Gradiente con colore Centrale
GradientPaint theGradientCenter = new GradientPaint(0, 160, Color.BLUE, 0, 220, new Color(0x66ffff), true);
graph2.setPaint(theGradientCenter);
graph2.fill(new Rectangle2D.Float(0,160,150,100));
```


# MOD 2


Obbiettivo: programmare con un uso disciplinato del typesystem
Pulizia del cast in java perchè permesso solo oggetti da un tipo a un suo sottotipo
Java imperativo(ha l'assegnamento (int x=12; x=13)) con stile ad oggetti, F# funzionale con anche gli oggetti
**Lambda espressioni : **sono funzioni anonime ed. F#: fun x -> x  Java: (x)->x






```java
//Per ovviare al limite di dover dichiarare in file esterni le classi metto static così le classi non dipendono dal loro contenitore


public class lezione03_02 {
	public static class Animal {
		//private int weight No perchè sarebbe inacessibile a Dog
		protected int weight;


		public Animal (int weight){
			this.weight = weight;
		}


		public void eat (Animal a) {
			weight += a.weight;
		}
	}
	//sottoclasse dog extended animal
	public static class Dog extends Animal {
		private String color;


		public Dog(int w, String c) {
			super(w);
			this.color = c;
		}


		//customizzare-specializzare eat
		@Override
		public void eat(Animal a) {
			weight += a.weight / 2;
		}


		public void bark() {}//abbaiare


	}


	public static class Cat extends Animal {
		private String color;


		public Cat(int w, String c) {
			super(w);//è come this ma non fa riferimento alla classe ma alla superclasse
			this.color = c;
		}


		//customizzare-specializzare eat
		@Override
		public void eat(Animal a) {
			weight += a.weight / 3;
			color = color + "fat";
		}


		public void meow() {}


	}


	public static void main(String[] args) {
		Dog fido = new Dog(15, "bruno");
		Dog baldo = new Dog(20, "bianco");
		Animal jackie = new Dog(2, "nero");//Si può fare perchè è sottotipo(gerarchia di ereditarietà) ed è un linguaggio ad oggetti
		Dog pluto = new Animal(50);
		Animal selene = new Cat(4, "grigio");//tipo in compile tipe è Animal poi in run time diventa Cat  (luna)
		//Dog fido2 = selene;	//ERRORE No tipo Animal dentro Dog
		//Cat selene2 = selene;	//ERRORE No tipo Animal dentro Cat
		selene.eat(fido);//SUBSUMPTIONT(Sussunzione(generalizzazzione) contrario Assunzione(specializzazzione)) dal tipo più specifico al generale
		//SUBSUMPTIONT è una forma di Polimorfismo capacità di una funzione di lavorare con variabili di tipo diverso
		//DINAMIC DISPANCING selene.eat prende quella di Cat perchè eseguita in runtime
		//VIRTUAL-TABLE: In memoria dell'oggetto sono i puntatori ai metodi
		
	}
}
```






## Ereditarietà


**Sub building**


## DINAMIC DISPANCING e Virtual table


Chiama l'override giusto anche se il tipo è una superclasse, permette customizzazzione-specializzazzione class estesa


Permette a run-time usare metodi specificati Animal meom = new Cat()    meom .eat()//è quello di Cat


|      Cat       |  \|  |      Pointer      |
| :------------: | :--: | :---------------: |
|  weight : int  |  \|  | eat_pointermetod  |
| color : String |  \|  | meow_pointermetod |
|    pointer     |  \|  |                   |


## Display MouseInput 


```java
public class Istogramma {


    public interface DisplayListener {
        public void cellClicked(int x, int y);
    }


    public static void main(String[] args) {
        JFrame window = new JFrame("Istogramma Display");
        window.setSize(800, 600);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //sett Display, sfondo
        histogramDisplay display = new histogramDisplay();
        //programma a cui passo il Display
        histogram run = new histogram(display);
        window.add(display);
        window.setVisible(true);
    }


    public static class histogramDisplay extends JComponent {
        //Componente che prende le coordinate di input al Click mouse
        public void addListener(DisplayListener listener) {
            this.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    listener.cellClicked(e.getX(), e.getY());
                }
            });
        }
	    //paintComponent si occupa dell'implementazione grafica
        public void paintComponent(Graphics gr) {
            Graphics2D g = (Graphics2D)gr;
            double w = getWidth();
            double h = getHeight();
            g.setColor(Color.black);//Seleziona colore
            g.setStroke(new BasicStroke(3, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));//setta la linea di disegno
            g.draw(new Line2D.Double(w/8,h/8,w/8, h*3/4));
            g.draw(new Line2D.Double(w/8,h*3/4,w*3/4, h*3/4));
        }


    }


    public static class histogram implements DisplayListener {
        private histogramDisplay display;


        public histogram(histogramDisplay display) {
            this.display = display;
            display.addListener(this);
        }


        @Override
        public void cellClicked(int x, int y) {
            JOptionPane.showMessageDialog(display, "Clicked at "+x+","+y);
        }
    }
}


```


