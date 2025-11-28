public interface IDestruivel {

    void receberDano(int quantidade);

    boolean estaDestruido();

    String getNome();
}