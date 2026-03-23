public class TIEFighter extends NaveEspacial {

    public TIEFighter(String idPiloto) {
        super("TIE Fighter " + idPiloto, 60, 0); // TIEs são mais frágeis
    }

    public TIEFighter(String idPiloto, int energiaCustomizada) {

        super("TIE Fighter " + idPiloto, energiaCustomizada, 0);
    }

    @Override
    public void mover() {
        System.out.println(getNome() + " manobra rapidamente! (Som: *TIEeeee*)");
    }

    @Override
    public void disparar() {
        System.out.println(getNome() + " dispara 2 lasers verdes!");
    }
}