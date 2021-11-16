int main(int argc, char**argv){
    void * parser = ParseAlloc(malloc);
    Parse(parser, INT, 15);
    Parse(parser, DIV, 0);
    Parse(parser, INT, 5);
    Parse(parser, 0, 0);
}