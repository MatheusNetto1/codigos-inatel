using System;

class Dog {
  public string NameDog {get; set;}
  public int IdadeDog {get; set;}

  public Dog(string nameDog, int idadeDog){
    NameDog = nameDog;
    IdadeDog = idadeDog;
  }

  public virtual void showName(){
    Console.WriteLine($"O nome do cachorro é: {NameDog}" );
  }

  public virtual void showIdade(){
    Console.WriteLine($"A idade do cachorro é: {IdadeDog}");
  }
}

class BigDog : Dog {
  private int Tamanho;
  public BigDog(string nameDog, int idadeDog, int tamanho) : base(nameDog, idadeDog){
    Tamanho = tamanho;
  }

  public override void showName(){
    Console.WriteLine($"O nome do cachorro grande é: {NameDog}" );
  }

  public override void showIdade(){
    Console.WriteLine($"A idade do cachorro grande é: {IdadeDog}");
  }

  public void showTamanho(){
    Console.WriteLine($"O tamanho do cachorro grande é: {Tamanho}cm");
  }
}

class SmallDog : Dog {
  public SmallDog(string nameDog, int idadeDog) : base(nameDog, idadeDog){
  }

  public override void showName(){
    Console.WriteLine($"O nome do cachorro pequeno é: {NameDog}" );
  }

  public override void showIdade(){
    Console.WriteLine($"A idade do cachorro pequeno é: {IdadeDog}");
  }
}

class Program {
  public static void Main (string[] args) {
    Dog d = new Dog("Farinha Láctea", 5);
    BigDog b = new BigDog("Ovomaltine", 4, 83);
    SmallDog s = new SmallDog("Jujuba", 7);

    showInfoAll(d, b, s);
  }

  public static void showInfoAll(Dog d, BigDog b, SmallDog s){
    Console.WriteLine("\t\t---Infos---");
    d.showName();
    b.showName();
    b.showTamanho();
    s.showName();
    showIdadeAll(b, s);
  }

  public static void showIdadeAll(BigDog b, SmallDog s){
    Console.WriteLine("\t\t---Idades---");
    b.showIdade();
    s.showIdade();
  }
}