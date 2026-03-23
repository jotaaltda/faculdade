public class YWing extends NaveEspacial implements IHiperdrive {

    public YWing(String nomePiloto) {
        super("Y-Wing de " + nomePiloto, 80, 50);
    }

    @Override
    public void mover() {
        System.out.println(getNome() + " se move lentamente, focada no bombardeio!");
    }

    @Override
    public void disparar() {
        System.out.println(getNome() + " dispara um torpedo de prótons!");
    }

    @Override
    public void saltarParaHiperespaco() {
        System.out.println("Y-Wing " + getNome() + ": Computador de navegação pronto. Saltando!");
    }

    // --- AQUI ESTAVA O ERRO: Havia uma chave } fechando a classe aqui antes ---


    public void ativarEscudosDefletores() {
        System.out.println(getNome() + " ativa escudos defletores!");
    }
}