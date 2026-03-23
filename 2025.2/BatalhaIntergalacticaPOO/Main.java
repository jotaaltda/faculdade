import java.util.List;

public class Main {

    public static void main(String[] args) {

        System.out.println("--- PARTE 1: DEMONSTRAÇÃO DE POLIMORFISMO (HERANÇA) ---");
        System.out.println("Criando uma lista do tipo ABSTRATO (NaveEspacial)...");

        List<NaveEspacial> esquadrao = List.of(
                new XWing("Luke Skywalker"),
                new TIEFighter("Piloto Imperial 001"),
                new XWing("Wedge Antilles"),
                new TIEFighter("Darth Vader (Protótipo TIE)", 150),
                new YWing("Tenente Lepira")
        );

        for (NaveEspacial nave : esquadrao) {
            nave.mover();
            nave.disparar();
            System.out.println("---");
        }

        System.out.println("\n--- PARTE 2: DEMONSTRAÇÃO DE SOBRECARGA (OVERLOAD) ---");

        XWing luke = (XWing) esquadrao.get(0);
        TIEFighter vader = (TIEFighter) esquadrao.get(3);

        // Método 1 (sem parâmetros)
        luke.disparar();

        // Método 2 (SOBRECARGA, com parâmetro)
        System.out.println("\n(Luke ataca Vader...)");
        luke.disparar(vader);

        System.out.println("\n--- PARTE 3: DEMONSTRAÇÃO DE POLIMORFISMO (INTERFACES) ---");
        System.out.println("Criando uma lista do tipo INTERFACE (IDestruivel)...");

        List<IDestruivel> alvosNaTrincheira = List.of(
                esquadrao.get(1),
                new TorreTurbolaser("Alfa-01"),
                esquadrao.get(0),
                new TorreTurbolaser("Beta-02"),
                esquadrao.get(4)
        );

        System.out.println("\n(Um ataque coordenado atinge todos os alvos...)");

        for (IDestruivel alvo : alvosNaTrincheira) {
            System.out.println("Atacando " + alvo.getNome() + "...");
            alvo.receberDano(70);

            if (alvo.estaDestruido()) {
                System.out.println(alvo.getNome() + " foi destruído!");
            }
            System.out.println("---");
        }

        System.out.println("\n--- MISSÃO 3 - RETIRADA ESTRATÉGICA ---");

        for (NaveEspacial nave : esquadrao) {

            if (nave instanceof IHiperdrive) {
                IHiperdrive naveComHiperdrive = (IHiperdrive) nave;
                naveComHiperdrive.saltarParaHiperespaco();
            } else {
                System.out.println(nave.getNome() + " não possui hiperdrive. Ficou para trás...");
            }
        }

        System.out.println("\n--- MISSÃO 4 - O COPILOTO (COMPOSIÇÃO) ---");

        if (esquadrao.get(0) instanceof XWing) {
            XWing lukeXWing = (XWing) esquadrao.get(0);

            System.out.println("Situação crítica! Escudos baixos!");
            lukeXWing.receberDano(40);

            lukeXWing.iniciarReparos();
        }

        System.out.println("\n--- RELATÓRIO FINAL (STATIC) ---");

        System.out.println("Total de naves construídas na simulação: " + NaveEspacial.getTotalNavesCriadas());

    }
}