public class XWing extends NaveEspacial implements IHiperdrive {

    private DroideAstromech droide;

    public XWing(String nomePiloto) {
        super("X-Wing de " + nomePiloto, 100, 50);
        this.droide = new DroideAstromech("R2-D2");
    }

    @Override
    public void mover() {
        System.out.println(getNome() + " avança pela trincheira em velocidade de ataque!");
    }

    @Override
    public void disparar() {
        System.out.println(getNome() + " dispara 4 lasers vermelhos interligados!");
    }

    @Override
    public void saltarParaHiperespaco() {
        System.out.println("X-Wing " + getNome() + ": Asas em posição de ataque. Entrando no hiperespaço!");
    }

    public void disparar(IDestruivel alvo) {
        System.out.println(getNome() + " mira e dispara lasers em " + alvo.getNome() + "!");

        alvo.receberDano(10);
        alvo.receberDano(10);
        alvo.receberDano(10);
        alvo.receberDano(10);
    }

    public void ativarEscudosDefletores() {
        System.out.println(getNome() + " ativa escudos defletores!");
    }

    public void iniciarReparos() {
        System.out.println(getNome() + ": 'R2, preciso de reparos agora!'");
        this.droide.reparar(this);
    }

}