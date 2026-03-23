public abstract class NaveEspacial implements IDestruivel {

    private static int totalNavesCriadas = 0;

    private String nome;
    private int energia;
    private int escudo;

    public NaveEspacial(String nome, int energiaInicial, int escudoInicial) {
        this.nome = nome;
        this.energia = energiaInicial;
        this.escudo = escudoInicial;

        totalNavesCriadas++;
    }

    public abstract void mover();

    public abstract void disparar();

    @Override
    public String getNome() {
        return this.nome;
    }

    @Override
    public void receberDano(int quantidade) {

        this.escudo -= quantidade;

        if (this.escudo < 0) {

            this.escudo = escudo * -1;
            energia -= this.escudo;

            if (this.energia < 0) {
                this.energia = 0;
            }

            this.escudo = 0;
        }

        System.out.println(this.nome + " foi atingido! escudo restante: " + this.escudo + " vida restante: " + this.energia);
    }

    @Override
    public boolean estaDestruido() {
        return this.energia <= 0;
    }

    public int getEnergia() {
        return this.energia;
    }

    public static int getTotalNavesCriadas() {
        return totalNavesCriadas;
    }

}