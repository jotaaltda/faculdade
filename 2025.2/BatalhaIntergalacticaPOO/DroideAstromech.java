public class DroideAstromech {

    private String nome;

    public DroideAstromech(String nome) {
        this.nome = nome;
    }

    public void reparar(NaveEspacial naveAlvo) {
        System.out.println("Bip Bop! " + this.nome + " está reparando os danos da " + naveAlvo.getNome() + "!");
    }
}