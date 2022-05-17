// Example02
// In the real world, you’d want creatures to be able to take on and lose bonuses arbitrarily, something which
// an append-only linked list doesn’t support. Furthermore, you don’t want to modify the underlying creature stats
// permanently (as we did)—instead, you want to keep modifications temporary.
// One way to implement CoR is through a centralized component.

// The component that we are going to build is called an event broker. Since it’s connected to every participating
// component, it represents the Mediator design pattern and, further, since it responds to queries through events,
// it leverages the Observer design pattern.


//We are using the Boost.Signals2 library for keeping a signal called queries. Essentially, what this lets us do is fire
// this signal and have it handled by every slot (listening component).
struct Game //mediator
{
    signal<void(&Query) queries;
};

//imagine that you want to query a creature’s statistic. You could certainly try to read a field, but remember:
// we need to apply all the modifiers before the final value is known. So instead we’ll encapsulate a query in
// a separate object (this is the Command pattern1) defined as follows:
struct Query
{
    string name;
    enum Argument { ATTACK, DEFENSE}  argument;
    int result;
};
// All we need to provide is the name of the creature and which statistic we’re interested in. It is precisely
// this value (well, a reference to it) that will be constructed and used by Game::queries to apply the modifiers
// and return the final value.

struct Creature
{
private:
    Game &game;
    int attack , defense ;
public:
    string name;
    Creature(Game &game): game(game) {}
    int get_attack()
    {
        Query p{ "name", Query::Argument::ATTACK, attack};
        game.queries(p);
        return  q.result;
};
