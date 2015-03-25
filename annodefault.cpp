#include "anno.h"

void set_anno_default()
{

	Position dummy;

	save_annotated_move=false;



char fen1[]="rn1qkb1r/1pp3pp/p4p2/3pp3/3PP1bN/N4P2/PPP3PP/R2QKB1R b KQkq -";
dummy.set_from_fen(fen1);
annotate_move(&dummy,"g4h3","?!");

char fen2[]="r1b1kb1r/pppp2pp/2n1pn2/5p2/1P6/4P1P1/P1PP1P1P/RNBQK2R w KQkq -";
dummy.set_from_fen(fen2);
annotate_move(&dummy,"d2d3","?!");

char fen3[]="r1b1kb1r/pppp2pp/2n1pn2/5p2/1P6/4P1P1/P1PP1P1P/RNBQK2R w KQkq -";
dummy.set_from_fen(fen3);
annotate_move(&dummy,"f2f3","?!");

char fen4[]="r1b1kb1r/pppp2pp/2n1pn2/5p2/1P6/4P1P1/P1PP1P1P/RNBQK2R w KQkq -";
dummy.set_from_fen(fen4);
annotate_move(&dummy,"h2h3","??");

char fen5[]="r1b1kb1r/pppp2pp/2n1pn2/5p2/1P6/4P1P1/P1PP1P1P/RNBQK2R w KQkq -";
dummy.set_from_fen(fen5);
annotate_move(&dummy,"g3g4","?!");

char fen6[]="b1k5/p1pp4/1p2p1p1/PP3p2/3PP3/N5P1/2PK1P1r/7R b - -";
dummy.set_from_fen(fen6);
annotate_move(&dummy,"f5e4","-");

char fen7[]="rn2k1nr/pp1q3p/B1p2pp1/3pp3/5Qb1/4P3/PPPP1PPP/RNB1K2R w KQkq -";
dummy.set_from_fen(fen7);
annotate_move(&dummy,"f4a4","?!");

char fen8[]="r1bqkbnr/ppp3pp/2n1pp2/1B6/3pP1P1/2P2N2/PP1P1P1P/RNBQK2R b KQkq -";
dummy.set_from_fen(fen8);
annotate_move(&dummy,"e6e5","?!");

char fen9[]="r1bqk2r/pppp2pp/2n1pp2/1B6/1b1PP3/2P5/PP3PP1/RNBQK2R b KQkq -";
dummy.set_from_fen(fen9);
annotate_move(&dummy,"h7h5","?!");

char fen10[]="rnbqkbnr/pppp2pp/4pp2/8/8/2N1P2N/PPPP1PPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen10);
annotate_move(&dummy,"f8b4","?!");

char fen11[]="r2q1k1r/p1Np2p1/bppbpp2/4P2p/2PP4/8/PP4PP/R1BQK2R b KQ -";
dummy.set_from_fen(fen11);
annotate_move(&dummy,"d6b4","?!");

char fen12[]="r2k1b1r/pp2p2p/4bnp1/1B1p4/8/4P3/PPPP1PPP/RNB1K2R w KQ -";
dummy.set_from_fen(fen12);
annotate_move(&dummy,"f2f3","!?");

char fen13[]="rnbqkbnr/pppp2pp/4pp2/8/8/2N1PN2/PPPP1PPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen13);
annotate_move(&dummy,"f8b4","?!");

char fen14[]="r2k1b1r/pp1B4/4pnpp/6B1/3P4/2N2P2/PPP3PP/R3K2R w KQ -";
dummy.set_from_fen(fen14);
annotate_move(&dummy,"e1c1","-");

char fen15[]="2k5/pbpp4/1p2p1p1/PP3p2/3PP3/N5P1/2PK1P1r/R7 b - -";
dummy.set_from_fen(fen15);
annotate_move(&dummy,"b7a8","-");

char fen16[]="rnb1k2r/pp5p/q1p1ppp1/3p4/2PP4/4P2B/P3NP1P/R1BQK1R1 b Qkq -";
dummy.set_from_fen(fen16);
annotate_move(&dummy,"a6a5","!!");

char fen17[]="rnbqkbnr/1ppp2pp/p4p2/8/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen17);
annotate_move(&dummy,"d1h5","!!");

char fen18[]="rnbqk1nr/pp1p2pp/2p1pp2/1B6/1b1P4/2N1P2N/PPP2PPP/R1BQK2R b KQkq d3";
dummy.set_from_fen(fen18);
annotate_move(&dummy,"g8h6","?!");

char fen19[]="rnbqkbnr/pppppppp/8/8/8/5N2/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen19);
annotate_move(&dummy,"d7d5","??");

char fen20[]="rnbqkbnr/pppppppp/8/8/8/5N2/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen20);
annotate_move(&dummy,"f7f5","??");

char fen21[]="rnbqkbnr/pppppppp/8/8/8/5N2/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen21);
annotate_move(&dummy,"d7d6","?");

char fen22[]="rnbqkbnr/pppppppp/8/8/8/5N2/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen22);
annotate_move(&dummy,"f7f6","!!");

char fen23[]="r2k1b1r/pp1B3p/4pnp1/8/8/5P2/PPPP2PP/RNB1K2R w KQ -";
dummy.set_from_fen(fen23);
annotate_move(&dummy,"d2d4","?!");

char fen24[]="r1bq1bnr/1p2pk1p/3p1pp1/1B6/8/4P3/PPPP1PPP/RNB1K2R w KQ -";
dummy.set_from_fen(fen24);
annotate_move(&dummy,"b5e8","?!");

char fen25[]="rnbqkb1r/ppp1p1pp/3p1p2/1N6/5P2/4P3/PPPP1nPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen25);
annotate_move(&dummy,"d1h5","!?");

char fen26[]="rnbq1k1r/ppNp2p1/2p1pp2/2b4p/3P4/2P1P3/PP4PP/R1BQKB1R b KQ d3";
dummy.set_from_fen(fen26);
annotate_move(&dummy,"c5d6","?!");

char fen27[]="rnbqkb1r/ppp1pppp/8/3p4/3P4/7P/PPP1PPP1/RN1QKBNR b KQkq -";
dummy.set_from_fen(fen27);
annotate_move(&dummy,"e7e5","?!");

char fen28[]="r2k1b1r/pp2p2p/4bnp1/1B6/8/1P3P2/P1PP2PP/RNB1K2R w KQ -";
dummy.set_from_fen(fen28);
annotate_move(&dummy,"d2d4","?!");

char fen29[]="rnbqkbnr/pppp2pp/4pp2/8/6P1/4PN2/PPPP1P1P/RNBQKB1R b KQkq g3";
dummy.set_from_fen(fen29);
annotate_move(&dummy,"b8c6","?!");

char fen30[]="rn2kbnr/pp2p1pp/2pq1p2/1B1pN3/6b1/4PQ2/PPPP1PPP/RNB1K2R w KQkq -";
dummy.set_from_fen(fen30);
annotate_move(&dummy,"b5c6","?!");

char fen31[]="rnbqkbnr/pppp1ppp/4p3/8/3P4/8/PPP1PPPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen31);
annotate_move(&dummy,"c2c4","??");

char fen32[]="r2k1b1r/pp1B3p/4pnp1/6B1/3P4/5P2/PPP3PP/RN2K2R w KQ -";
dummy.set_from_fen(fen32);
annotate_move(&dummy,"b1c3","-");

char fen33[]="r1bqkbnr/pppp2pp/n3pp2/8/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen33);
annotate_move(&dummy,"d1h5","?!");

char fen34[]="rn1k1bnr/pp1Np1pp/5p2/3p4/8/4P3/PPPP1PPP/RNB1K2R w KQ -";
dummy.set_from_fen(fen34);
annotate_move(&dummy,"d7b8","?!");

char fen35[]="rnbqk1nr/pppp2pp/4pp2/1B6/1b6/2N1P2N/PPPP1PPP/R1BQK2R b KQkq -";
dummy.set_from_fen(fen35);
annotate_move(&dummy,"c7c6","?!");

char fen36[]="rnbqkbnr/pppp1p1p/4p1p1/8/4P2Q/8/PPPP1PPP/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen36);
annotate_move(&dummy,"d8f6","?!");

char fen37[]="rn1qk2r/ppp4p/6pb/3pp3/5P2/8/PPPP3P/RNBQK2R w KQkq e6";
dummy.set_from_fen(fen37);
annotate_move(&dummy,"d1e2","??");

char fen38[]="rnbqkbnr/pppp3p/4p1p1/8/5Q2/4P3/PPPP1PPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen38);
annotate_move(&dummy,"f8b4","?!");

char fen39[]="r4rk1/p3p2p/6pb/1p1p4/3P4/N3PB2/PP4PP/R3K2R w KQ -";
dummy.set_from_fen(fen39);
annotate_move(&dummy,"e1g1","?!");

char fen40[]="rnbqkbnr/pppp2pp/4p3/5p2/8/4PQ1N/PPPP1PPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen40);
annotate_move(&dummy,"d8h4","!?");

char fen41[]="rnb1k1nr/pppp2pp/4p3/8/1b5q/2P2QP1/PP1P1P1P/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen41);
annotate_move(&dummy,"h4d4","!!");

char fen42[]="rnq1kbnr/pp3N1p/2p2pp1/1B1pp3/5Qb1/4P3/PPPP1PPP/RNB1K2R w KQkq e6";
dummy.set_from_fen(fen42);
annotate_move(&dummy,"f7d6","?!");

char fen43[]="rnbqkbnr/ppppp2p/5pp1/8/4P2N/8/PPPP1PPP/RNBQKB1R b KQkq e3";
dummy.set_from_fen(fen43);
annotate_move(&dummy,"e7e6","?!");

char fen44[]="rnbqkb1r/ppppp1pp/5p1n/8/3N4/7P/PPPPPPP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen44);
annotate_move(&dummy,"b7b5","-");

char fen45[]="rnbqkb1r/ppppp1pp/5p1n/8/3N4/7P/PPPPPPP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen45);
annotate_move(&dummy,"b8c6","?!");

char fen46[]="rnbqkb1r/ppppp1pp/5p1n/8/3N4/7P/PPPPPPP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen46);
annotate_move(&dummy,"a7a6","?!");

char fen47[]="rnbqkb1r/ppppp1pp/5p1n/8/3N4/7P/PPPPPPP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen47);
annotate_move(&dummy,"c7c6","?!");

char fen48[]="rnbqkb1r/ppppp1pp/5p1n/8/3N4/7P/PPPPPPP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen48);
annotate_move(&dummy,"b8a6","?!");

char fen49[]="rnbqkbnr/pppp1ppp/4p3/8/2PP4/8/PP2PPPP/RNBQKBNR b KQkq c3";
dummy.set_from_fen(fen49);
annotate_move(&dummy,"d8h4","!!");

char fen50[]="rnbqkbnr/pp1pp1pp/2p2p2/8/8/4PN2/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen50);
annotate_move(&dummy,"f3d4","!");

char fen51[]="rnbqkbnr/pppp2pp/8/4ppN1/3P4/8/PPP1PPPP/RNBQKB1R b KQkq d3";
dummy.set_from_fen(fen51);
annotate_move(&dummy,"d7d5","?");

char fen52[]="rnbqkb2/pp1p2p1/2p5/4p3/5p1P/8/PPPPPPP1/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen52);
annotate_move(&dummy,"e2e3","?!");

char fen53[]="rnq1k1nr/p5pp/5p2/2ppp3/1Q4b1/4P3/PPPP1PPP/RNB1K2R w KQkq -";
dummy.set_from_fen(fen53);
annotate_move(&dummy,"b4b7","?!");

char fen54[]="rnbqkb1r/1ppp3p/p3ppp1/8/3PP3/P1N5/1PP2PPP/R1BQKB1R b KQkq d3";
dummy.set_from_fen(fen54);
annotate_move(&dummy,"d7d5","?!");

char fen55[]="rnbqkb1r/ppppp1pp/5p1n/8/8/2N2N1P/PPPPPPP1/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen55);
annotate_move(&dummy,"h6g4","?!");

char fen56[]="rnbqk2r/pppp2pp/4pn2/8/1bB5/2P2Q2/PP1P1PPP/RNB1K1NR b KQkq -";
dummy.set_from_fen(fen56);
annotate_move(&dummy,"f6e4","!!");

char fen57[]="2k4r/p1pp4/bp2p1p1/1P3p2/P2PP3/N5P1/2P1KP2/R7 b - -";
dummy.set_from_fen(fen57);
annotate_move(&dummy,"h8h2","-");

char fen58[]="rnbqk1nr/pppp2pp/4pp2/8/1b1N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen58);
annotate_move(&dummy,"b1c3","!?");

char fen59[]="rnbqkb1r/pppp1ppp/4p2n/3N4/3P4/8/PPP1PPPP/R1BQKBNR b KQkq d3";
dummy.set_from_fen(fen59);
annotate_move(&dummy,"d8h4","?!");

char fen60[]="rnbqkb1r/ppp1p1pp/5p2/3p4/3PP3/5N2/PPP2PPP/RN1QKB1R b KQkq -";
dummy.set_from_fen(fen60);
annotate_move(&dummy,"e7e5","?!");

char fen61[]="rnbqkb1r/pppp2pp/4pp2/8/4P3/2N5/PPPP1PPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen61);
annotate_move(&dummy,"f8b4","?");

char fen62[]="rnbqkb1r/pppp2pp/4pp2/8/4P3/2N5/PPPP1PPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen62);
annotate_move(&dummy,"a7a6","?!");

char fen63[]="2r1Brk1/pp5p/4ppp1/3p4/1b6/2Q1P3/PP1P1P1P/R3K2R w KQ -";
dummy.set_from_fen(fen63);
annotate_move(&dummy,"e8g6","!");

char fen64[]="rnb1k1nr/pppp1ppp/4p3/8/1bPPq3/2N1P1P1/PP3P1P/R1BQKBNR b KQkq -";
dummy.set_from_fen(fen64);
annotate_move(&dummy,"e4c2","!!");

char fen65[]="r2q1k1r/p1Np2p1/bpp1pp2/4P2p/1bPP4/8/PP2K1PP/R1BQ3R b - -";
dummy.set_from_fen(fen65);
annotate_move(&dummy,"b4d2","!?");

char fen66[]="r2q1k1r/p1Np2p1/bpp1pp2/4P2p/1bPP4/8/PP2K1PP/R1BQ3R b - -";
dummy.set_from_fen(fen66);
annotate_move(&dummy,"b4e1","?");

char fen67[]="rnbqkbnr/ppp1p1pp/5p2/8/8/5N2/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen67);
annotate_move(&dummy,"d8d2","!!");

char fen68[]="rnbqkb1r/pp1pp1p1/2p2p2/7p/8/2N1P1P1/PPPP1P2/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen68);
annotate_move(&dummy,"d7d5","?!");

char fen69[]="rnbqkbnr/pp1p3p/4ppp1/1Q6/8/4P3/PPPP1PPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen69);
annotate_move(&dummy,"b8c6","?!");

char fen70[]="rnbqk1nr/pppp1ppp/4p3/8/8/4PQ2/PP1P1PPP/RNB1K1NR b KQkq -";
dummy.set_from_fen(fen70);
annotate_move(&dummy,"f7f5","-");

char fen71[]="rn1qkbnr/ppp1p1pp/5p2/3pN3/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen71);
annotate_move(&dummy,"e5d7","!!");

char fen72[]="rnbqkbnr/pppp2pp/4pp2/3P4/8/5N2/PPP1PPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen72);
annotate_move(&dummy,"f8c5","?!");

char fen73[]="rnbqkbnr/1ppp3p/p4pp1/7Q/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen73);
annotate_move(&dummy,"h5d5","!!");

char fen74[]="rnq1kbnr/ppp2Npp/4pp2/3p4/6b1/4PQ2/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen74);
annotate_move(&dummy,"f1b5","?!");

char fen75[]="rnbqkbnr/pppp1ppp/4p3/8/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen75);
annotate_move(&dummy,"d8f6","?!");

char fen76[]="rnbqkbnr/pp1pp2p/2p2pp1/8/3P4/2N1P2N/PPP2PPP/R1BQKB1R b KQkq d3";
dummy.set_from_fen(fen76);
annotate_move(&dummy,"g8h6","?!");

char fen77[]="rnbqkb1r/pppp2pp/4pp2/3N4/8/2P2P1N/PP1PPnPP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen77);
annotate_move(&dummy,"d1a4","!");

char fen78[]="rnb1kbnr/pppp1ppp/4p3/3P4/8/6P1/PP2PP1P/R3KBNR w KQkq -";
dummy.set_from_fen(fen78);
annotate_move(&dummy,"a1d1","??");

char fen79[]="rnbqkb1r/pp5p/2p1ppp1/3p4/3P4/4P2B/PPP1NP1P/R1BQK1R1 b Qkq -";
dummy.set_from_fen(fen79);
annotate_move(&dummy,"d8a5","!?");

char fen80[]="rnbqkb1r/pp1pp2p/2p2ppn/8/3P2P1/2N1P2N/PPP2P1P/R1BQKB1R b KQkq g3";
dummy.set_from_fen(fen80);
annotate_move(&dummy,"h6g4","?!");

char fen81[]="rn1qk2r/ppp1p2p/5ppb/3pP3/8/3P1Q2/PPP2P1P/RNB1K2R b KQkq -";
dummy.set_from_fen(fen81);
annotate_move(&dummy,"h6d2","!!");

char fen82[]="r1bqkb1r/ppppp2p/2n1Ppp1/8/8/8/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen82);
annotate_move(&dummy,"d7e6","-");

char fen83[]="rnb1k2r/pp4pp/2p1pp1n/1B6/1b6/2N1P3/PPPP1PPP/R1BQK2R w KQkq -";
dummy.set_from_fen(fen83);
annotate_move(&dummy,"g2g4","?!");

char fen84[]="rnbqkb1r/ppppp1pp/8/8/4PPn1/2N5/PPPP2PP/R1BQKB1R b KQkq f3";
dummy.set_from_fen(fen84);
annotate_move(&dummy,"c7c6","?!");

char fen85[]="rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3";
dummy.set_from_fen(fen85);
annotate_move(&dummy,"d7d5","?!");

char fen86[]="rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3";
dummy.set_from_fen(fen86);
annotate_move(&dummy,"e7e6","-");

char fen87[]="rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3";
dummy.set_from_fen(fen87);
annotate_move(&dummy,"g8f6","?!");

char fen88[]="rnbqkb1r/pp1p3p/2p1ppp1/8/3P4/2N1P2B/PPP2P1P/R1BQK1R1 b Qkq -";
dummy.set_from_fen(fen88);
annotate_move(&dummy,"d7d5","?!");

char fen89[]="rnbqkbnr/pp1p2pp/2p1pp2/1N6/8/4P3/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen89);
annotate_move(&dummy,"c6b5","?!");

char fen90[]="r4bnr/1p3k1p/4ppp1/8/8/4P3/PPPP1PPP/RNB1K2R b KQ -";
dummy.set_from_fen(fen90);
annotate_move(&dummy,"a8a2","?!");

char fen91[]="rnbqkbnr/ppp1p2p/6p1/3pQ3/8/4P3/PPPP1PPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen91);
annotate_move(&dummy,"c8e6","-");

char fen92[]="rnbqkbnr/ppp1p2p/6p1/3pQ3/8/4P3/PPPP1PPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen92);
annotate_move(&dummy,"e7e6","?");

char fen93[]="rnb1k1nr/pppp2pp/4p3/8/1b5q/2P2Q2/PP1P1PPP/RNB1KBNR w KQkq -";
dummy.set_from_fen(fen93);
annotate_move(&dummy,"g2g3","??");

char fen94[]="rnb1kbnr/pppp1p1p/4p1p1/8/4P3/8/PPPP1PPP/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen94);
annotate_move(&dummy,"g8f6","?!");

char fen95[]="rnbqkb1r/ppppp1pp/5p2/8/4P3/8/PPPP1PPP/RNBQKB1R b KQkq e3";
dummy.set_from_fen(fen95);
annotate_move(&dummy,"d7d5","?!");

char fen96[]="rnbqkb1r/ppppp1pp/5p2/8/4P3/8/PPPP1PPP/RNBQKB1R b KQkq e3";
dummy.set_from_fen(fen96);
annotate_move(&dummy,"e7e6","?!");

char fen97[]="rnbqkb1r/ppppp1pp/5p2/8/4P3/8/PPPP1PPP/RNBQKB1R b KQkq e3";
dummy.set_from_fen(fen97);
annotate_move(&dummy,"g7g6","-");

char fen98[]="rnbqkb1r/pp1pp1pp/2p2p1n/8/3N4/2N4P/PPPPPPP1/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen98);
annotate_move(&dummy,"b7b5","?!");

char fen99[]="rnbqkb1r/pp1pp1pp/2p2p1n/8/3N4/2N4P/PPPPPPP1/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen99);
annotate_move(&dummy,"e7e5","?!");

char fen100[]="rnbqkbnr/pp1pp2p/2p2pp1/8/8/2N1PN2/PPPP1PPP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen100);
annotate_move(&dummy,"c3d5","!");

char fen101[]="rnbqkb1r/pp1p3p/2p1pppn/1B6/3Q4/4P3/PPPP1PPP/RNB1K1NR b KQkq -";
dummy.set_from_fen(fen101);
annotate_move(&dummy,"d7d5","?!");

char fen102[]="rnbqkbnr/pp1p3p/2p1ppp1/8/4P2N/8/PPPPBPPP/RNBQK2R b KQkq -";
dummy.set_from_fen(fen102);
annotate_move(&dummy,"d7d5","?!");

char fen103[]="rn1qkb1r/1pp3pp/p4p2/3pp3/3PP3/N4P2/PPP4P/R2QKB1R b KQkq -";
dummy.set_from_fen(fen103);
annotate_move(&dummy,"g7g6","?!");

char fen104[]="rnbqk1nr/pppp2pp/4pp2/2bP4/8/4PN2/PPP2PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen104);
annotate_move(&dummy,"g8h6","?!");

char fen105[]="rnbqkbnr/pppppppp/8/8/3P4/8/PPP1PPPP/RNBQKBNR b KQkq d3";
dummy.set_from_fen(fen105);
annotate_move(&dummy,"g8h6","?!");

char fen106[]="rnbqkbnr/pppppppp/8/8/3P4/8/PPP1PPPP/RNBQKBNR b KQkq d3";
dummy.set_from_fen(fen106);
annotate_move(&dummy,"e7e6","?!");

char fen107[]="r1bqk2r/pppp2p1/2n1pp2/1B1P3p/1b2P3/2P5/PP3PP1/RNBQK2R b KQkq -";
dummy.set_from_fen(fen107);
annotate_move(&dummy,"d7d6","?!");

char fen108[]="rnbqkbnr/pppp2pp/4p3/5p2/3N3P/4P3/PPPP1PP1/RNBQKB1R b KQkq h3";
dummy.set_from_fen(fen108);
annotate_move(&dummy,"f8b4","!?");

char fen109[]="rnb2rk1/pp4pp/2p1pp1n/1B6/1b4P1/2N1P3/PPPP1P1P/R1BQK2R w KQ -";
dummy.set_from_fen(fen109);
annotate_move(&dummy,"h2h4","?!");

char fen110[]="rnbqkb1r/pp1pp1pp/2p2p1n/8/4P1P1/2N2N2/PPPP1P1P/R1BQKB1R b KQkq e3";
dummy.set_from_fen(fen110);
annotate_move(&dummy,"e7e5","?!");

char fen111[]="rnb1kbnr/pppp2pp/4p3/5p2/8/4P3/PPPP1PPP/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen111);
annotate_move(&dummy,"g8f6","?!");

char fen112[]="rnbqkbnr/ppppp1pp/5p2/8/3N4/8/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen112);
annotate_move(&dummy,"g8h6","!");

char fen113[]="rnb1kbnr/pppp2pp/4p3/1N3p2/7q/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen113);
annotate_move(&dummy,"g2g3","?!");

char fen114[]="r4b1r/pp1p1kpp/4pp2/1B6/5Pn1/2P1P3/PPnP2PP/RNBQK2R w KQ -";
dummy.set_from_fen(fen114);
annotate_move(&dummy,"e1f1","?!");

char fen115[]="rnbqkb1r/pppp2pp/5p2/4p3/4P3/2P5/PP1P1PP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen115);
annotate_move(&dummy,"d7d5","?!");

char fen116[]="rnbqkbnr/pppp2pp/4p3/5p2/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen116);
annotate_move(&dummy,"d4b5","?!");

char fen117[]="rnbqkbnr/pppp2pp/4p3/5p2/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen117);
annotate_move(&dummy,"d1h5","-");

char fen118[]="rnbqkbnr/pppp2pp/4p3/5p2/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen118);
annotate_move(&dummy,"b2b4","?");

char fen119[]="rnbqkbnr/pppp2pp/4p3/5p2/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen119);
annotate_move(&dummy,"h2h4","?");

char fen120[]="rnbqkbnr/pppp2pp/4p3/5p2/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen120);
annotate_move(&dummy,"a2a3","?!");

char fen121[]="rnbqkbnr/pppp2pp/4p3/5p2/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen121);
annotate_move(&dummy,"g2g3","?");

char fen122[]="rnbqkbnr/pppp2pp/4p3/5p2/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen122);
annotate_move(&dummy,"f1b5","?");

char fen123[]="rnbqkb1r/pppp1ppp/4p2n/3N4/8/5P2/PPPPP1PP/R1BQKBNR b KQkq -";
dummy.set_from_fen(fen123);
annotate_move(&dummy,"d8h4","!!");

char fen124[]="rnbqkbnr/pppp3p/4p1p1/5p1Q/3N4/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen124);
annotate_move(&dummy,"h5g5","?!");

char fen125[]="rnb1kb1r/pp5p/q1p1ppp1/3p4/2PP4/4P2B/PP2NP1P/R1BQK1R1 b Qkq -";
dummy.set_from_fen(fen125);
annotate_move(&dummy,"f8a3","!");

char fen126[]="2r1k2r/1p4pp/p3pp1n/3pP3/2B3P1/8/PP3PKP/3R4 b k -";
dummy.set_from_fen(fen126);
annotate_move(&dummy,"d5d4","?!");

char fen127[]="rnbqkb1r/ppppp1pp/5p1n/8/8/4PN2/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen127);
annotate_move(&dummy,"f3e5","!!");

char fen128[]="rnbqkb1r/pp2p1p1/2p2p2/3p3p/8/1PN1P1P1/P1PP1P2/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen128);
annotate_move(&dummy,"e7e5","?!");

char fen129[]="r1bqkb1r/pppp2pp/2n1pp1n/4P1N1/8/2P5/PP1P1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen129);
annotate_move(&dummy,"h6g4","?!");

char fen130[]="rnbqkbnr/pppp3p/4ppp1/1B6/4P2N/8/PPPP1PPP/RNBQK2R b KQkq -";
dummy.set_from_fen(fen130);
annotate_move(&dummy,"c7c6","?!");

char fen131[]="rnbqkbnr/pppp1ppp/4p3/8/8/3BP3/PPPP1PPP/RNBQK1NR b KQkq -";
dummy.set_from_fen(fen131);
annotate_move(&dummy,"f8b4","-");

char fen132[]="rnbqkb1r/pp1pp1pp/2p2p1n/8/1P1N2P1/8/P1PPPP1P/RNBQKB1R b KQkq b3";
dummy.set_from_fen(fen132);
annotate_move(&dummy,"e7e5","?!");

char fen133[]="rnb1k2r/pppp1ppp/4pq1n/8/3PP3/2N2N2/PP3PPP/R1BQK2R b KQkq d3";
dummy.set_from_fen(fen133);
annotate_move(&dummy,"h6g4","!!");

char fen134[]="r3kb1r/1p1p2pp/p3pp1n/8/2B1P1P1/8/PP1P1P1P/2R1K2R b Kkq -";
dummy.set_from_fen(fen134);
annotate_move(&dummy,"f8b4","?!");

char fen135[]="rnb1k1nr/pppp1ppp/4pq2/8/4P3/2N2N2/PP1P1PPP/R1BQK2R b KQkq -";
dummy.set_from_fen(fen135);
annotate_move(&dummy,"g8h6","!?");

char fen136[]="r2q1k1r/p1Np2p1/bppbpp2/4P2p/3P4/2P5/PP4PP/R1BQK2R w KQ -";
dummy.set_from_fen(fen136);
annotate_move(&dummy,"c3c4","?!");

char fen137[]="rnbqkb1r/pppppppp/5n2/8/8/6P1/PPPPPPBP/RNBQK1NR b KQkq -";
dummy.set_from_fen(fen137);
annotate_move(&dummy,"f6g4","!!");

char fen138[]="rnb1kb1r/pp1pp1pp/2p2p1n/q7/2PN2P1/2N5/PP1PPP1P/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen138);
annotate_move(&dummy,"a5g5","!!");

char fen139[]="rnb1kbnr/pp1p3p/2p1ppp1/1N5Q/qP6/4P3/P1PP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen139);
annotate_move(&dummy,"h5h7","!?");

char fen140[]="rnbqkbnr/p1ppp1pp/5p2/1p6/8/4PN2/PPPP1PPP/RNBQKB1R w KQkq b6";
dummy.set_from_fen(fen140);
annotate_move(&dummy,"f3e5","!!");

char fen141[]="rnbqkb1r/ppppp1pp/5p1n/4N3/8/2N5/PPPPPPPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen141);
annotate_move(&dummy,"f6e5","?!");

char fen142[]="rnbqkbnr/pppp2pp/4p3/5p2/3N4/P3P3/1PPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen142);
annotate_move(&dummy,"b8c6","?!");

char fen143[]="r1bqkb1r/pppp2pp/2n1pp2/4P1N1/5Pn1/2P5/PP1P2PP/RNBQKB1R b KQkq f3";
dummy.set_from_fen(fen143);
annotate_move(&dummy,"g4f2","?!");

char fen144[]="rnbqk2r/pp1p2p1/2p1pp2/2bN3p/8/2P1P3/PP1P2PP/R1BQKB1R w KQkq h6";
dummy.set_from_fen(fen144);
annotate_move(&dummy,"d5c7","!");

char fen145[]="rnbqkb1r/ppp1p1pp/5p1n/3pP3/6P1/5N2/PPPP1P1P/RNBQKB1R b KQkq g3";
dummy.set_from_fen(fen145);
annotate_move(&dummy,"c8g4","?!");

char fen146[]="rnb1k1nr/pppp2pp/4p3/5p2/1P6/4P3/P2P1P1P/RNB1K2R b KQkq b3";
dummy.set_from_fen(fen146);
annotate_move(&dummy,"g8f6","?!");

char fen147[]="rnbqkbnr/ppppppp1/7p/8/5N2/8/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen147);
annotate_move(&dummy,"d7d5","?!");

char fen148[]="rnbqkbnr/ppppppp1/7p/8/5N2/8/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen148);
annotate_move(&dummy,"e7e5","-");

char fen149[]="rnbqkbnr/pppp1ppp/4p3/8/8/4PQ2/PPPP1PPP/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen149);
annotate_move(&dummy,"f7f5","!");

char fen150[]="r2qk2r/ppp3p1/2np1p2/1B1Pp1Bp/1b2P1b1/2P3Q1/PP3PP1/RN2K2R b KQkq -";
dummy.set_from_fen(fen150);
annotate_move(&dummy,"g4f3","!");

char fen151[]="rnb1kbnr/pp1p1ppp/2p1pq2/8/2B1P3/5N2/PPPP1PPP/RNBQK2R b KQkq -";
dummy.set_from_fen(fen151);
annotate_move(&dummy,"g8h6","-");

char fen152[]="rn1qkb1r/ppp1p1pp/5p2/3pP3/8/8/PPPP1P1P/RNBQK2R b KQkq -";
dummy.set_from_fen(fen152);
annotate_move(&dummy,"g7g6","?!");

char fen153[]="rnbqk2r/pp1p2pp/2p1pp2/2bN4/8/2P1P3/PP1P2PP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen153);
annotate_move(&dummy,"h7h5","?!");

char fen154[]="r1bqkbnr/1p2p2p/3p1pp1/8/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen154);
annotate_move(&dummy,"f1b5","?!");

char fen155[]="rnbqkbnr/p1ppp2p/6p1/1p5Q/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen155);
annotate_move(&dummy,"h5d5","!!");

char fen156[]="r2k1b1r/pp2p2p/4bnp1/1B6/3p4/4PP2/PPPP2PP/RNB1K2R w KQ -";
dummy.set_from_fen(fen156);
annotate_move(&dummy,"b2b3","-");

char fen157[]="r2k1b1r/pp2p2p/4bnp1/1B6/3p4/4PP2/PPPP2PP/RNB1K2R w KQ -";
dummy.set_from_fen(fen157);
annotate_move(&dummy,"a2a4","?!");

char fen158[]="rnbqkb1r/pppppppp/5n2/8/3P4/2P5/PP2PPPP/RNBQKBNR b KQkq d3";
dummy.set_from_fen(fen158);
annotate_move(&dummy,"f6e4","!!");

char fen159[]="r1bqkbnr/ppppp2p/2n3p1/7Q/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen159);
annotate_move(&dummy,"h5d5","!!");

char fen160[]="rnb1kb2/pp1p4/2p1ppp1/1N6/1P6/4P3/2PP1PPP/2B1KB1R w KQkq -";
dummy.set_from_fen(fen160);
annotate_move(&dummy,"b5a7","!?");

char fen161[]="rnbqkb1r/ppppp1pp/5p2/8/8/2N5/PPPPPPP1/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen161);
annotate_move(&dummy,"c7c6","?!");

char fen162[]="rnbqkbnr/pp1p2pp/2p5/4ppN1/8/6P1/PPPPPP1P/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen162);
annotate_move(&dummy,"b2b4","?!");

char fen163[]="rnbqk2r/pppp2pp/4pp1n/2bP4/8/4PN1P/PPP2PP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen163);
annotate_move(&dummy,"c5b4","?!");

char fen164[]="rnbqkbnr/pp1ppppp/2p5/8/8/5N2/PPPPPPPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen164);
annotate_move(&dummy,"f3e5","!!");

char fen165[]="r1bqkb2/ppp3p1/n7/3p4/4Pp2/P7/1PP2PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen165);
annotate_move(&dummy,"f1b5","!!");

char fen166[]="r1bqkbnr/pppp3p/n3ppp1/7Q/3N4/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen166);
annotate_move(&dummy,"d4b5","?!");

char fen167[]="r1bqkb1r/ppp3pp/2n2p2/1B2p3/3pP1P1/2PP1N2/PP3P1P/RN1QK2R b KQkq -";
dummy.set_from_fen(fen167);
annotate_move(&dummy,"c8g4","?!");

char fen168[]="r1bqkbnr/1p1p3p/4ppp1/1B6/8/4P3/PPPP1PPP/RNB1K2R b KQkq -";
dummy.set_from_fen(fen168);
annotate_move(&dummy,"e8f7","?!");

char fen169[]="rnbqkb1r/pppp2pp/4pp1n/8/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen169);
annotate_move(&dummy,"d4b5","?!");

char fen170[]="rnbqkb1r/ppppp1pp/5p1n/8/4P3/2N2N2/PPPP1PPP/R1BQKB1R b KQkq e3";
dummy.set_from_fen(fen170);
annotate_move(&dummy,"h6g4","!!");

char fen171[]="rnbqkbnr/ppp1p1pp/5p2/3p4/8/4PN2/PPPP1PPP/RNBQKB1R w KQkq d6";
dummy.set_from_fen(fen171);
annotate_move(&dummy,"f3g5","?!");

char fen172[]="rnbqkbnr/ppp1p1pp/5p2/3p4/8/4PN2/PPPP1PPP/RNBQKB1R w KQkq d6";
dummy.set_from_fen(fen172);
annotate_move(&dummy,"f3e5","!?");

char fen173[]="rnbqkb1r/ppppp2p/6pn/7Q/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen173);
annotate_move(&dummy,"h5g5","!!");

char fen174[]="rnbqkb1r/pp1pp2p/2p3p1/8/4PP2/2N5/PPPP2P1/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen174);
annotate_move(&dummy,"d7d5","?!");

char fen175[]="r1b1Bbnr/1p2p2p/3pkpp1/q7/3P4/4P3/PPP2PPP/RNB1K2R w KQ -";
dummy.set_from_fen(fen175);
annotate_move(&dummy,"b1c3","!!");

char fen176[]="rnbqkbnr/pp1p2pp/2p5/5pN1/3Pp3/4P3/PPP2PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen176);
annotate_move(&dummy,"g5h7","?!");

char fen177[]="r1bqkbnr/pppp2pp/2n1pp2/8/6P1/2P1PN2/PP1P1P1P/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen177);
annotate_move(&dummy,"d7d5","?!");

char fen178[]="rnbqk2r/pp1p2p1/5p2/2p4p/8/4P3/PP3PP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen178);
annotate_move(&dummy,"d7d5","?!");

char fen179[]="rnbqkbnr/pppp1ppp/4p3/8/8/4P3/PPPP1PPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen179);
annotate_move(&dummy,"d1f3","?!");

char fen180[]="r1bqkbnr/ppp3pp/2n2p2/1B2p3/3pP1P1/2PP1N2/PP3P1P/RNBQK2R b KQkq -";
dummy.set_from_fen(fen180);
annotate_move(&dummy,"g8h6","?!");

char fen181[]="2kr2nr/1p2p1bp/p3b1p1/3p4/8/BP2P3/P1PP1PPP/RN2KB1R w KQ -";
dummy.set_from_fen(fen181);
annotate_move(&dummy,"a3e7","!");

char fen182[]="rnbqkbnr/pp1p3p/2p1p1p1/1B3pQ1/4P3/8/PPPP1PPP/RNB1K1NR b KQkq -";
dummy.set_from_fen(fen182);
annotate_move(&dummy,"g8f6","?!");

char fen183[]="rnbqkbnr/pppp1ppp/4p3/4P3/8/8/PPPP1PPP/RNBQKBNR b KQkq -";
dummy.set_from_fen(fen183);
annotate_move(&dummy,"d8h4","!!");

char fen184[]="rnb1k1nr/pppp2pp/4p3/5p2/7q/4PQPN/PP1P1P1P/RNB1K2R b KQkq -";
dummy.set_from_fen(fen184);
annotate_move(&dummy,"h4g3","!");

char fen185[]="r1bqBbnr/1p2p2p/3pkpp1/8/8/4P3/PPPP1PPP/RNB1K2R w KQ -";
dummy.set_from_fen(fen185);
annotate_move(&dummy,"d2d4","?!");

char fen186[]="rnbqkbnr/pp2p2p/3p1pp1/7Q/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen186);
annotate_move(&dummy,"h5b5","?!");

char fen187[]="rnbqkbnr/pppp2pp/4p3/1N3p2/8/4P3/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen187);
annotate_move(&dummy,"d8h4","!?");

char fen188[]="r1bqkbnr/pppp3p/4ppp1/1N5Q/1n6/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen188);
annotate_move(&dummy,"h5h4","?!");

char fen189[]="r1bqk2r/pppp3p/n3ppp1/8/3P4/P3P3/1P3PP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen189);
annotate_move(&dummy,"h7h5","?!");

char fen190[]="rnbqkbnr/p1p1p2p/3p2p1/1p1Q4/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen190);
annotate_move(&dummy,"d5f7","!!");

char fen191[]="rnbq1k1r/ppNp2p1/2pbpp2/7p/3P4/2P1P3/PP4PP/R1BQKB1R w KQ -";
dummy.set_from_fen(fen191);
annotate_move(&dummy,"e3e4","!?");

char fen192[]="rnb1kb1r/pp1pp2p/q1p2ppn/1N5Q/1P6/4P3/P1PP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen192);
annotate_move(&dummy,"b5a7","!");

char fen193[]="rnb1kbnr/pppp2pp/4p3/5p2/7q/4P1QN/PPPP1PPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen193);
annotate_move(&dummy,"b7b5","!?");

char fen194[]="rnb1kbnr/pppp1ppp/4pq2/8/4P3/5N2/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen194);
annotate_move(&dummy,"b1c3","??");

char fen195[]="rn2k1nr/pp5p/B1p2pp1/3ppq2/Q5b1/4P3/PPPP1PPP/RNB1K2R w KQkq -";
dummy.set_from_fen(fen195);
annotate_move(&dummy,"a4g4","!?");

char fen196[]="3k1b1r/pp2p1pp/5p1n/3p4/8/4P3/PPPP1PPP/RNB1K2R w KQ -";
dummy.set_from_fen(fen196);
annotate_move(&dummy,"g2g4","?!");

char fen197[]="rnb1kb1r/pppp1ppp/4p2n/3N4/3Pq3/4P1P1/PPP2P1P/R1BQKBNR b KQkq -";
dummy.set_from_fen(fen197);
annotate_move(&dummy,"f8b4","?!");

char fen198[]="rnbqkbnr/pp1p1ppp/2p1p3/1B6/4P3/5N2/PPPP1PPP/RNBQK2R b KQkq -";
dummy.set_from_fen(fen198);
annotate_move(&dummy,"d8f6","-");

char fen199[]="r1bqkbnr/pp1pp2p/2n3p1/1B6/8/4P3/PPPP1PPP/R1BQK2R w KQkq -";
dummy.set_from_fen(fen199);
annotate_move(&dummy,"d1f3","!!");

char fen200[]="r2qkb1r/ppp1p2p/2n2pp1/8/3P2b1/5P2/PPP3PP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen200);
annotate_move(&dummy,"c6b4","-");

char fen201[]="r3k2r/pp5p/4pppn/3p4/1b6/2Q1P3/PP1P1PPP/R3KB1R w KQkq -";
dummy.set_from_fen(fen201);
annotate_move(&dummy,"g2g4","?!");

char fen202[]="r3kb1r/p3p2p/4bnp1/1p1p4/3P4/4PP2/PPP3PP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen202);
annotate_move(&dummy,"f6g4","?!");

char fen203[]="rnbqkb1r/pppppppp/8/8/3Pn3/2P2P2/PP2P1PP/RNBQKBNR b KQkq -";
dummy.set_from_fen(fen203);
annotate_move(&dummy,"e4d2","!!");

char fen204[]="rnb1k1nr/pppp1ppp/4p3/8/1bPPq3/2N1B1P1/PP2PP1P/R2QKBNR b KQkq -";
dummy.set_from_fen(fen204);
annotate_move(&dummy,"e4c2","!!");

char fen205[]="r1b1kb1r/pppp2pp/2n1pn2/5p2/8/4PPP1/PPPP3P/RNBQK2R w KQkq -";
dummy.set_from_fen(fen205);
annotate_move(&dummy,"c2c3","?!");

char fen206[]="rnbqkb1r/ppppp2p/5pp1/4P3/8/8/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen206);
annotate_move(&dummy,"f8h6","-");

char fen207[]="rnbqkb1r/ppppp2p/5pp1/4P3/8/8/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen207);
annotate_move(&dummy,"b8c6","?!");

char fen208[]="2r1k2r/1p4pp/p3pp1n/4P3/P1Bp2P1/8/1P3PKP/3R4 b k a3";
dummy.set_from_fen(fen208);
annotate_move(&dummy,"e8g8","?!");

char fen209[]="rnbqkbnr/ppppp1pp/8/5p2/8/5N2/PPPPPPPP/RNBQKB1R w KQkq f6";
dummy.set_from_fen(fen209);
annotate_move(&dummy,"f3e5","!!");

char fen210[]="r1bqkb1r/pppp2pp/4pp1n/8/8/4PP2/PPPP2PP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen210);
annotate_move(&dummy,"c7c6","!?");

char fen211[]="rnbqkb1r/pp1pp1pp/2p2p1n/8/3N2P1/2P5/PP1PPP1P/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen211);
annotate_move(&dummy,"e7e5","?!");

char fen212[]="4kbnr/pp2p2p/2r1b1p1/1B1p4/8/4P3/PPPP1PPP/RNB1K2R w KQk -";
dummy.set_from_fen(fen212);
annotate_move(&dummy,"b1c3","!?");

char fen213[]="rnbqkb1r/ppp2p1p/6p1/4p3/3P4/7P/PPP2PP1/RN1QKBNR b KQkq -";
dummy.set_from_fen(fen213);
annotate_move(&dummy,"d8g5","!?");

char fen214[]="rn1qkb1r/ppp1p2p/5pp1/3pP3/8/5Q2/PPPP1P1P/RNB1K2R b KQkq -";
dummy.set_from_fen(fen214);
annotate_move(&dummy,"f8h6","!");

char fen215[]="rnbqk1nr/pppp2pp/4pp2/8/8/4P3/PPPP1PPP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen215);
annotate_move(&dummy,"d1h5","!");

char fen216[]="r1bq1k1r/ppNp2p1/n1pbpp2/7p/3PP3/2P5/PP4PP/R1BQKB1R w KQ -";
dummy.set_from_fen(fen216);
annotate_move(&dummy,"f1a6","?!");

char fen217[]="r2qkb1r/ppp3pp/2n5/1B2pp1Q/3pP3/2PP4/PP3P1P/RN2K1R1 b Qkq -";
dummy.set_from_fen(fen217);
annotate_move(&dummy,"g7g6","?!");

char fen218[]="r1bqkbnr/pppp2pp/n7/4ppN1/3P4/8/PPP1PPPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen218);
annotate_move(&dummy,"a2a3","?!");

char fen219[]="rnbqkb1r/pppp1ppp/4p3/8/3PP3/8/PPP2PPP/RN1QKBNR b KQkq -";
dummy.set_from_fen(fen219);
annotate_move(&dummy,"b8c6","?!");

char fen220[]="rnbqkbnr/ppppp1pp/5p2/8/8/4P2N/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen220);
annotate_move(&dummy,"e7e6","-");

char fen221[]="rnbqkbnr/ppppp1pp/5p2/8/8/4P2N/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen221);
annotate_move(&dummy,"g7g6","?!");

char fen222[]="r3k2r/1p1p2pp/p3pp1n/8/1bB1P1P1/8/PP1P1P1P/2R2K1R b kq -";
dummy.set_from_fen(fen222);
annotate_move(&dummy,"b4d2","?!");

char fen223[]="rnq1kbnr/pp3Npp/2p1pp2/1B1p4/6b1/4PQ2/PPPP1PPP/RNB1K2R w KQkq -";
dummy.set_from_fen(fen223);
annotate_move(&dummy,"f7d6","?!");

char fen224[]="rnbqkbnr/pp1p1ppp/2p1p3/1B5Q/8/4P3/PPPP1PPP/RNB1K1NR b KQkq -";
dummy.set_from_fen(fen224);
annotate_move(&dummy,"g7g6","-");

char fen225[]="r3k2r/1p1p2pp/p3pp1n/8/2B1P1P1/8/PP3PKP/7R b kq -";
dummy.set_from_fen(fen225);
annotate_move(&dummy,"d7d5","?!");

char fen226[]="rn1qkb1r/1pp4p/p5p1/3pp3/3P4/N4P1B/PPP4P/R2QK2R b KQkq -";
dummy.set_from_fen(fen226);
annotate_move(&dummy,"d8h4","!!");

char fen227[]="rnbq1k1r/ppNp2p1/2p1pp2/2b4p/8/2P1P3/PP1P2PP/R1BQKB1R w KQ -";
dummy.set_from_fen(fen227);
annotate_move(&dummy,"d2d4","!?");

char fen228[]="r1bqk2r/pppp2pp/2n1pp1n/1B6/1b1PP3/2P2N1P/PP3PP1/RNBQK2R b KQkq -";
dummy.set_from_fen(fen228);
annotate_move(&dummy,"h6g4","?!");

char fen229[]="rnbqkb1r/p1pp2p1/1p2pp2/7p/3PP3/8/PPPNBPP1/R1BQK2R b KQkq -";
dummy.set_from_fen(fen229);
annotate_move(&dummy,"f8b4","?!");

char fen230[]="rn1qkbnr/ppp1p1pp/5p2/3p4/3P2bN/5P2/PPP1P1PP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen230);
annotate_move(&dummy,"e7e5","?!");

char fen231[]="rnbqkbnr/ppppp1pp/5p2/8/8/2N2N2/PPPPPPPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen231);
annotate_move(&dummy,"g8h6","!");

char fen232[]="rnbqkbnr/ppppp1pp/5p2/8/8/2N2N2/PPPPPPPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen232);
annotate_move(&dummy,"e7e6","?");

char fen233[]="rnbqkbnr/ppppp1pp/5p2/8/8/2N2N2/PPPPPPPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen233);
annotate_move(&dummy,"c7c6","?!");

char fen234[]="r1bqkbnr/pppppppp/2n5/8/8/5N2/PPPPPPPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen234);
annotate_move(&dummy,"f3g5","!!");

char fen235[]="r1bqkbnr/pppp2pp/2n1pp2/4P3/8/2P2N2/PP1P1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen235);
annotate_move(&dummy,"g8h6","?!");

char fen236[]="rnb1k2r/ppp3pp/4pp1n/8/1b6/2N1P3/PPPP1PPP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen236);
annotate_move(&dummy,"f1b5","?!");

char fen237[]="rnbqkbnr/ppp4p/4p1p1/3pQ3/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen237);
annotate_move(&dummy,"e5c7","!");

char fen238[]="rnbqkbnr/pp2p1pp/3p1p2/8/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen238);
annotate_move(&dummy,"d1h5","?!");

char fen239[]="rnbqkbnr/pp1p1p1p/2p1p1p1/1B4Q1/8/4P3/PPPP1PPP/RNB1K1NR b KQkq -";
dummy.set_from_fen(fen239);
annotate_move(&dummy,"f7f6","?!");

char fen240[]="r4rk1/p3p2p/6p1/1p1p4/3P1b2/N3PB2/PP4PP/R4RK1 w - -";
dummy.set_from_fen(fen240);
annotate_move(&dummy,"h2h4","?!");

char fen241[]="2k5/p1pp4/bp2p1p1/1P3p2/P2PP3/N5P1/2PK1P1r/R7 b - -";
dummy.set_from_fen(fen241);
annotate_move(&dummy,"a6b7","-");

char fen242[]="r3kbnr/p3p2p/4b1p1/1p1p4/8/4P3/PPPP1PPP/RNB1KB1R w KQkq b6";
dummy.set_from_fen(fen242);
annotate_move(&dummy,"d2d4","?!");

char fen243[]="r1bq1bnr/1p1p1k1p/4ppp1/1B6/8/4P3/PPPP1PPP/RNB1K2R w KQ -";
dummy.set_from_fen(fen243);
annotate_move(&dummy,"b5d7","?!");

char fen244[]="rnbqkb1r/ppppp1pp/5p1n/1N6/8/8/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen244);
annotate_move(&dummy,"h6g4","!!");

char fen245[]="2k4r/1p5p/p4np1/3p4/8/1P2P3/P1PPBPPP/4K2R w KQ -";
dummy.set_from_fen(fen245);
annotate_move(&dummy,"e2g4","?!");

char fen246[]="rnbqkbnr/pppp2pp/5p2/4p1N1/8/8/PPPPPPPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen246);
annotate_move(&dummy,"e2e4","!?");

char fen247[]="1q2kb1r/p2p2pp/2p1pp1n/8/1P4P1/2P5/P2PPPBP/RNB1K2R b KQkq b3";
dummy.set_from_fen(fen247);
annotate_move(&dummy,"b8f4","!!");

char fen248[]="rnbqkbnr/pppp1pp1/7p/4p3/5N2/8/PPPPPPPP/RNBQKB1R w KQkq e6";
dummy.set_from_fen(fen248);
annotate_move(&dummy,"f4d5","??");

char fen249[]="r1bqkbnr/ppppp2p/5pp1/7Q/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen249);
annotate_move(&dummy,"h5d5","!!");

char fen250[]="rnbqkb1r/ppp1p2p/3p1pp1/1N5Q/5P2/4P3/PPPP1nPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen250);
annotate_move(&dummy,"b5c7","!?");

char fen251[]="r2k1b1r/pp1B4/4p1p1/8/3P4/2N2P2/PPP3PP/2KR3R w - -";
dummy.set_from_fen(fen251);
annotate_move(&dummy,"h1e1","!");

char fen252[]="rnbqkb1r/pp1p2pp/2p2p1n/1B2p1N1/4P3/8/PPPP1PPP/RNBQK2R w KQkq -";
dummy.set_from_fen(fen252);
annotate_move(&dummy,"g5h7","?!");

char fen253[]="rnbqkb1r/pppp2pp/4pp2/8/4P3/8/PPPPBPP1/RNBQK2R b KQkq -";
dummy.set_from_fen(fen253);
annotate_move(&dummy,"h7h5","?!");

char fen254[]="rnbqk2r/pppp2pp/4pp2/2bN4/6n1/2P2P1N/PP1PP1PP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen254);
annotate_move(&dummy,"e2e3","!");

char fen255[]="rnb1kb1r/pp1p1ppp/2p1pq1n/8/2B1P3/5N1P/PPPP1PP1/RNBQK2R b KQkq -";
dummy.set_from_fen(fen255);
annotate_move(&dummy,"h6g4","!!");

char fen256[]="r3kb1r/1p1pp1pp/p4p1n/8/2B1P1P1/8/PP1P1P1P/R3K2R b KQkq -";
dummy.set_from_fen(fen256);
annotate_move(&dummy,"e7e6","?!");

char fen257[]="rnbqkbnr/pppp1ppp/4p3/3P4/8/8/PPP1PPPP/RNBQKBNR b KQkq -";
dummy.set_from_fen(fen257);
annotate_move(&dummy,"d8h4","!");

char fen258[]="rnbqk1nr/pppp2pp/8/4p3/1b6/2P1P3/PP1P1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen258);
annotate_move(&dummy,"d1g4","!!");

char fen259[]="r3kb1r/p3p2p/4bnp1/1p1p4/3P4/4P3/PPP2PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen259);
annotate_move(&dummy,"f2f3","?!");

char fen260[]="rnb1kb1r/pp1pp1pp/2p2p1n/6q1/2PN2P1/2N1P3/PP1P1P1P/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen260);
annotate_move(&dummy,"g5h4","!!");

char fen261[]="rnbqkbnr/ppppp2p/5pp1/8/8/4PN2/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen261);
annotate_move(&dummy,"b1c3","!");

char fen262[]="rnbqk1nr/pppp2pp/4p3/8/1b6/2P2Q2/PP1P1PPP/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen262);
annotate_move(&dummy,"d8h4","!!");

char fen263[]="rnbqk1nr/pppp2pp/4p3/8/1b6/2P2Q2/PP1P1PPP/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen263);
annotate_move(&dummy,"g8f6","?!");

char fen264[]="r1b2rk1/p1pp1p1p/1pn1pnpb/1B6/4PPP1/2P4P/PP1P4/RNB1K1NR b KQ g3";
dummy.set_from_fen(fen264);
annotate_move(&dummy,"c6b4","?!");

char fen265[]="rnb1kbnr/pppp1ppp/4p3/8/2PPq3/4B1P1/PP2PP1P/RN1QKBNR b KQkq -";
dummy.set_from_fen(fen265);
annotate_move(&dummy,"f8b4","!!");

char fen266[]="rnbqkb1r/pppppppp/8/8/3P4/8/PPP1PPPP/RN1QKBNR b KQkq -";
dummy.set_from_fen(fen266);
annotate_move(&dummy,"d7d5","?!");

char fen267[]="rnbq1bnr/p1pkpQ1p/3p2p1/1p6/8/4P3/PPPP1PPP/RNB1KB1R w KQ -";
dummy.set_from_fen(fen267);
annotate_move(&dummy,"f7e7","!!");

char fen268[]="r1b1k3/p1pp4/1p2p1p1/5p2/PP1PP3/6P1/2P2P2/RN3K2 b kq a3";
dummy.set_from_fen(fen268);
annotate_move(&dummy,"c8a6","?!");

char fen269[]="rnbqkbnr/pp1p3p/2p1ppp1/1B6/7Q/4P3/PPPP1PPP/RNB1K1NR b KQkq -";
dummy.set_from_fen(fen269);
annotate_move(&dummy,"g8h6","?!");

char fen270[]="rnbqkbnr/ppp1pppp/8/3p4/8/5N2/PPPPPPPP/RNBQKB1R w KQkq d6";
dummy.set_from_fen(fen270);
annotate_move(&dummy,"f3e5","!!");

char fen271[]="rnbqk2r/pp1p2pp/2p1pp1n/1B6/1b1P4/2N1P1PN/PPP2P1P/R1BQK2R b KQkq -";
dummy.set_from_fen(fen271);
annotate_move(&dummy,"h6g4","!");

char fen272[]="rnbqkb1r/pppp2pp/5p1n/4p1N1/4P3/8/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen272);
annotate_move(&dummy,"f1b5","?!");

char fen273[]="rnbqkb1r/pppp2pp/4pp2/3N4/6n1/2P2P1N/PP1PP1PP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen273);
annotate_move(&dummy,"f8c5","?!");

char fen274[]="rnbqkb1r/pppp2pp/4pp2/3N4/6n1/2P2P1N/PP1PP1PP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen274);
annotate_move(&dummy,"g4f2","?");

char fen275[]="rnbqkb1r/pppp2pp/4pp2/3N4/6n1/2P2P1N/PP1PP1PP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen275);
annotate_move(&dummy,"e6d5","??");

char fen276[]="rnbqkbnr/pppp2pp/4pp2/8/3PP3/5N2/PPP2PPP/RNBQKB1R b KQkq d3";
dummy.set_from_fen(fen276);
annotate_move(&dummy,"b8c6","!?");

char fen277[]="rn1qk2r/ppp4p/6pb/3pp3/5P2/8/PPPPQ2P/RNB1K2R b KQkq -";
dummy.set_from_fen(fen277);
annotate_move(&dummy,"d8h4","!!");

char fen278[]="r3kbnr/p3p2p/4b1p1/1p1p4/3P4/4P3/PPP2PPP/RNB1KB1R b KQkq d3";
dummy.set_from_fen(fen278);
annotate_move(&dummy,"g8f6","?!");

char fen279[]="rnbqkb1r/pp1pp1pp/2p2p2/8/8/2N1P3/PPPP1PP1/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen279);
annotate_move(&dummy,"h7h5","?!");

char fen280[]="rnbqkbnr/ppppp1pp/5p2/8/8/5N1P/PPPPPPP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen280);
annotate_move(&dummy,"e7e5","?!");

char fen281[]="rnbqkb1r/pp1p3p/2p1pppn/1B1N4/8/4PN2/PPPP1PPP/R1BQK2R w KQkq -";
dummy.set_from_fen(fen281);
annotate_move(&dummy,"d5c7","!");

char fen282[]="r3k1nr/1p2p1bp/p3b1p1/3p4/8/1P2P3/P1PP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen282);
annotate_move(&dummy,"c1a3","!");

char fen283[]="rnbqk1nr/ppp4p/3pppp1/2Q5/8/4P3/PPPP1PPP/R1B1KB1R w KQkq -";
dummy.set_from_fen(fen283);
annotate_move(&dummy,"c5c7","!");

char fen284[]="rnbqkbnr/pp1p1ppp/2p1p3/1B6/4P3/5Q2/PPPP1PPP/RNB1K1NR b KQkq -";
dummy.set_from_fen(fen284);
annotate_move(&dummy,"f7f5","?!");

char fen285[]="rnbqkbnr/pppp2pp/4pp2/8/8/4PN2/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen285);
annotate_move(&dummy,"f3d4","!?");

char fen286[]="rnb1kbnr/pppp2pp/4p3/1N3p2/7q/4P1P1/PPPP1P1P/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen286);
annotate_move(&dummy,"h4c4","!?");

char fen287[]="r2qkb1r/ppp1p2p/5ppB/8/1n1P2b1/5P2/PPP3PP/RN1QKB1R b KQkq -";
dummy.set_from_fen(fen287);
annotate_move(&dummy,"f8h6","-");

char fen288[]="rnbqkbnr/pppp2pp/5p2/4p3/8/4PN2/PPPP1PPP/RNBQKB1R w KQkq e6";
dummy.set_from_fen(fen288);
annotate_move(&dummy,"f3g5","!");

char fen289[]="rnbqkbnr/pppp2pp/5p2/4p1N1/8/4P3/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen289);
annotate_move(&dummy,"f6g5","??");

char fen290[]="rnbqkbnr/pppp2pp/5p2/4p1N1/8/4P3/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen290);
annotate_move(&dummy,"g7g6","-");

char fen291[]="rnbqkbnr/ppppp2p/6p1/8/6Q1/4P3/PPPP1PPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen291);
annotate_move(&dummy,"e7e6","?!");

char fen292[]="rnb1kb1r/pppp2pp/4pn2/5p2/8/4P1P1/PPPP1P1P/RNBQK2R w KQkq -";
dummy.set_from_fen(fen292);
annotate_move(&dummy,"f2f3","?!");

char fen293[]="rnbqkbnr/ppp1p1pp/5p2/3p4/4P3/5N2/PPPP1PPP/RNBQKB1R w KQkq d6";
dummy.set_from_fen(fen293);
annotate_move(&dummy,"e4d5","??");

char fen294[]="rnbqk2r/pp1p2pp/2p1pp2/2bN4/6n1/2P1PP1N/PP1P2PP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen294);
annotate_move(&dummy,"f3g4","!?");

char fen295[]="rnbqkbnr/pp1p2pp/4pp2/8/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen295);
annotate_move(&dummy,"d1h5","?!");

char fen296[]="rnbqkbnr/pp1p2pp/2p5/4ppN1/7P/8/PPPPPPP1/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen296);
annotate_move(&dummy,"g5h7","?!");

char fen297[]="r1bqk1nr/pppp2pp/2n1pp2/1B6/1b1PP3/2P2N2/PP3PPP/RNBQK2R b KQkq -";
dummy.set_from_fen(fen297);
annotate_move(&dummy,"g8h6","?!");

char fen298[]="rnbqk2r/pppp2pp/4pp1n/3P4/1b6/2P1PN1P/PP3PP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen298);
annotate_move(&dummy,"h6g4","?!");

char fen299[]="rnbqkbnr/ppp3pp/3p4/4p1N1/3PPp2/8/PPP2PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen299);
annotate_move(&dummy,"g5h7","?!");

char fen300[]="rnb1kb1r/pp5p/2p1ppp1/q2p4/3P4/2P1P2B/PP2NP1P/R1BQK1R1 b Qkq -";
dummy.set_from_fen(fen300);
annotate_move(&dummy,"a5a6","!?");

char fen301[]="r2k3r/pp1B3p/4pnpb/8/3P4/5P2/PPP3PP/RNB1K2R w KQ -";
dummy.set_from_fen(fen301);
annotate_move(&dummy,"c1g5","-");

char fen302[]="2r2rk1/1p4pp/p3pp1n/4P1P1/P1Bp4/8/1P3PKP/3R4 b - -";
dummy.set_from_fen(fen302);
annotate_move(&dummy,"h6g4","!!");

char fen303[]="rnbqkbnr/pppp1ppp/4p3/8/8/4PN2/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen303);
annotate_move(&dummy,"d8f6","?!");

char fen304[]="r1bqkb1r/ppp1p2p/2n2pp1/8/3P4/8/PPP2PPP/RNBQKB1R b KQkq d3";
dummy.set_from_fen(fen304);
annotate_move(&dummy,"c8g4","-");

char fen305[]="r2q1k1r/p1Np2p1/bpp1pp2/4P2p/1bPP4/8/PP4PP/R1BQK2R w KQ -";
dummy.set_from_fen(fen305);
annotate_move(&dummy,"e1e2","?!");

char fen306[]="rnbqkb1r/pp1pp1pp/2p2p1n/8/2PN2P1/8/PP1PPP1P/RNBQKB1R b KQkq c3";
dummy.set_from_fen(fen306);
annotate_move(&dummy,"d8a5","!!");

char fen307[]="r3kb1r/pp1p2pp/4pp1n/8/8/5N2/PPPPPPPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen307);
annotate_move(&dummy,"h6g4","!!");

char fen308[]="rnbqkbnr/pppppppp/8/8/8/4P3/PPPP1PPP/RNBQKBNR b KQkq -";
dummy.set_from_fen(fen308);
annotate_move(&dummy,"e7e6","!?");

char fen309[]="rn1qkbnr/ppp3pp/5p2/8/3p2bN/3Q1P2/PPP1P1PP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen309);
annotate_move(&dummy,"f8b4","!!");

char fen310[]="rnb1kbnr/pppp1ppp/4pq2/8/2B1P3/5N2/PPPP1PPP/RNBQK2R b KQkq -";
dummy.set_from_fen(fen310);
annotate_move(&dummy,"f8b4","?!");

char fen311[]="r1b1k2r/p1pp1p1p/1pn1pnpb/1B6/4PP2/2P4P/PP1P2P1/RNB1K1NR b KQkq f3";
dummy.set_from_fen(fen311);
annotate_move(&dummy,"e8g8","?!");

char fen312[]="rnbqkbnr/ppppp2p/5p2/4N1p1/8/4P3/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen312);
annotate_move(&dummy,"f6e5","??");

char fen313[]="rnbqkbnr/ppp1p1pp/8/3p3Q/8/4P3/PPPP1PPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen313);
annotate_move(&dummy,"g7g6","-");

char fen314[]="r1b1kb2/pppp4/4p1p1/5p2/1P6/4PnP1/P1PP1P1P/RNB2K1R b kq -";
dummy.set_from_fen(fen314);
annotate_move(&dummy,"f3h2","-");

char fen315[]="r1bqkb1r/ppppp1pp/5p1n/8/6P1/1QP5/PP1PPP1P/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen315);
annotate_move(&dummy,"e7e6","?!");

char fen316[]="rn1qk2r/ppp1p2p/6pb/3p4/5P2/8/PPPP3P/RNBQK2R b KQkq f3";
dummy.set_from_fen(fen316);
annotate_move(&dummy,"e7e5","?!");

char fen317[]="rnbqkbnr/pppp1ppp/4p3/8/3PP3/8/PPP2PPP/RNBQKBNR b KQkq d3";
dummy.set_from_fen(fen317);
annotate_move(&dummy,"g8h6","?!");

char fen318[]="r1b1kb1r/pppp2pp/4pn2/8/1P1PPp2/3n1PP1/P1P1Q2P/RNB2K1R w kq -";
dummy.set_from_fen(fen318);
annotate_move(&dummy,"c2c4","?!");

char fen319[]="r1b1kb1r/pppp2pp/4pn2/8/1P1PPp2/3n1PP1/P1P1Q2P/RNB2K1R w kq -";
dummy.set_from_fen(fen319);
annotate_move(&dummy,"g3f4","?");

char fen320[]="r1b1kb1r/pppp2pp/4pn2/8/1P1PPp2/3n1PP1/P1P1Q2P/RNB2K1R w kq -";
dummy.set_from_fen(fen320);
annotate_move(&dummy,"c2c3","?!");

char fen321[]="r1b1kb1r/pppp2pp/4pn2/8/1P1PPp2/3n1PP1/P1P1Q2P/RNB2K1R w kq -";
dummy.set_from_fen(fen321);
annotate_move(&dummy,"g3g4","?");

char fen322[]="rnbqk1nr/pppp3p/4ppp1/7Q/8/4P3/PPPP1PPP/R1B1KB1R w KQkq -";
dummy.set_from_fen(fen322);
annotate_move(&dummy,"h5c5","!");

char fen323[]="rnb1kbnr/pppp2pp/4p3/1N3p2/2q5/4P1P1/PPPP1P1P/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen323);
annotate_move(&dummy,"d2d3","?!");

char fen324[]="rnb1kbnr/pppp2pp/4p3/1N3p2/2q5/4P1P1/PPPP1P1P/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen324);
annotate_move(&dummy,"f1d3","?");

char fen325[]="rnb1kbnr/pppp2pp/4p3/1N3p2/2q5/4P1P1/PPPP1P1P/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen325);
annotate_move(&dummy,"f1c4","?!");

char fen326[]="rnbqkbnr/ppppp1pp/5p2/8/7N/8/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen326);
annotate_move(&dummy,"d7d5","-");

char fen327[]="rnbqkbnr/ppppp1pp/5p2/8/7N/8/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen327);
annotate_move(&dummy,"g7g6","?!");

char fen328[]="rnbqkbnr/pppppppp/8/8/8/2N5/PPPPPPPP/R1BQKBNR b KQkq -";
dummy.set_from_fen(fen328);
annotate_move(&dummy,"g8h6","?!");

char fen329[]="rnbqkb1r/pp1pp2p/2p2pp1/8/3P4/2N1P2B/PPP2P1P/R1BQK2R b KQkq -";
dummy.set_from_fen(fen329);
annotate_move(&dummy,"e7e6","?!");

char fen330[]="rn1qkbnr/ppp3pp/4pp2/3pN3/6b1/4PQ2/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen330);
annotate_move(&dummy,"e5f7","?!");

char fen331[]="rnbqkbnr/ppp1p1pp/5p2/3p4/3PP3/5N2/PPP2PPP/RNBQKB1R b KQkq d3";
dummy.set_from_fen(fen331);
annotate_move(&dummy,"g8h6","?!");

char fen332[]="rnbqkb1r/pppp1ppp/4pn2/8/3P1B2/8/PPP1PPPP/RN1QKBNR w KQkq -";
dummy.set_from_fen(fen332);
annotate_move(&dummy,"f4c7","??");

char fen333[]="rnbqk2r/p1p3p1/1p1ppp2/3P3p/4PB2/8/PP2BPP1/R2QK2R b KQkq -";
dummy.set_from_fen(fen333);
annotate_move(&dummy,"e6e5","?!");

char fen334[]="rnbqkbnr/ppp1p1pp/8/3pNp2/8/8/PPPPPPPP/RNBQKB1R w KQkq d6";
dummy.set_from_fen(fen334);
annotate_move(&dummy,"e5d7","!!");

char fen335[]="rnbqkbnr/pppppppp/8/8/6P1/8/PPPPPP1P/RNBQKBNR b KQkq g3";
dummy.set_from_fen(fen335);
annotate_move(&dummy,"b8c6","?!");

char fen336[]="rnbqkbnr/ppppp1pp/5p2/8/8/5N2/PPPPPPPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen336);
annotate_move(&dummy,"e2e3","!");

char fen337[]="r1b1kbnr/pppp2pp/2n1p3/5p2/8/4P1P1/PPPP1P1P/RNBQK2R w KQkq -";
dummy.set_from_fen(fen337);
annotate_move(&dummy,"b2b4","?!");

char fen338[]="rnbqkb1r/1ppp2pp/p3pp2/8/4P3/P1N5/1PPP1PPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen338);
annotate_move(&dummy,"g7g6","?!");

char fen339[]="r3kb1r/pp1pp1pp/5p1n/8/4P1P1/8/PP1P1P1P/R3KB1R b KQkq -";
dummy.set_from_fen(fen339);
annotate_move(&dummy,"a7a6","?!");

char fen340[]="r1b1k3/p1pp4/1p2p1pb/5pB1/1P1PP3/6P1/P1P2P2/RN3K2 b kq -";
dummy.set_from_fen(fen340);
annotate_move(&dummy,"h6g5","?!");

char fen341[]="r1bqkbnr/pppp2pp/4p3/5p2/8/P3P3/1PPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen341);
annotate_move(&dummy,"g8f6","?!");

char fen342[]="rnb1kb1r/pppp2pp/4pn2/5p2/8/4PP2/PPPP2PP/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen342);
annotate_move(&dummy,"b8c6","?!");

char fen343[]="rnbqkb1r/1pp4p/p3pppB/3p4/3PP3/P1N5/1PP2PPP/R2QKB1R b KQkq -";
dummy.set_from_fen(fen343);
annotate_move(&dummy,"f8h6","?!");

char fen344[]="rnbqkb1r/ppppp1pp/5p1n/5N2/8/8/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen344);
annotate_move(&dummy,"h6f5","!");

char fen345[]="rnbqkbnr/pppp1ppp/4p3/1B6/4P3/8/PPPP1PPP/RNBQK1NR b KQkq -";
dummy.set_from_fen(fen345);
annotate_move(&dummy,"c7c6","?!");

char fen346[]="r1bqkb1r/pppp2pp/n3pp1n/1N6/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen346);
annotate_move(&dummy,"b5c7","?!");

char fen347[]="rnbqkb1r/ppppp1pp/5p1n/3N4/8/5N2/PPPPPPPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen347);
annotate_move(&dummy,"e7e6","!?");

char fen348[]="rnbqk1nr/pppp2pp/4p3/5p2/8/4PQ1N/PP1P1PPP/RNB1K2R b KQkq -";
dummy.set_from_fen(fen348);
annotate_move(&dummy,"d8h4","!");

char fen349[]="rnb1kb1r/pp1pp2p/2p2ppn/qN5Q/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen349);
annotate_move(&dummy,"b2b4","?!");

char fen350[]="r1bqkbnr/pp2p2p/2np1pp1/1Q6/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen350);
annotate_move(&dummy,"b5b6","?!");

char fen351[]="rnbqkb1r/pppp2pp/4pp1n/3N4/8/2P4N/PP1PPPPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen351);
annotate_move(&dummy,"b7b5","?");

char fen352[]="rnbqkb1r/pppp2pp/4pp1n/3N4/8/2P4N/PP1PPPPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen352);
annotate_move(&dummy,"c7c6","?");

char fen353[]="rnbqkb1r/pppp2pp/4pp1n/3N4/8/2P4N/PP1PPPPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen353);
annotate_move(&dummy,"h6g4","?!");

char fen354[]="rnbqkb1r/pppp2pp/4pp1n/3N4/8/2P4N/PP1PPPPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen354);
annotate_move(&dummy,"e6d5","??");

char fen355[]="r1bqkb1r/pppp2pp/2n1pp2/4P1N1/5P2/2P2Q2/PP1P1nPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen355);
annotate_move(&dummy,"f6g5","?!");

char fen356[]="rnbqkbnr/ppppp2p/5pp1/8/8/2N1P2N/PPPP1PPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen356);
annotate_move(&dummy,"c7c6","?!");

char fen357[]="rn2kbnr/pp2p1pp/5p2/3pN3/8/4P3/PPPP1PPP/RNB1K2R w KQkq -";
dummy.set_from_fen(fen357);
annotate_move(&dummy,"e5d7","?!");

char fen358[]="rnb1kbnr/pp1p2pp/1qp5/4ppN1/1P6/6P1/P1PPPP1P/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen358);
annotate_move(&dummy,"e2e3","?!");

char fen359[]="rnbqkbnr/ppp1p1pp/5p2/3pN3/8/4P3/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen359);
annotate_move(&dummy,"f6e5","?!");

char fen360[]="rnbqkbnr/ppp1p1pp/5p2/3pN3/8/4P3/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen360);
annotate_move(&dummy,"c8g4","?!");

char fen361[]="r4b1r/pp1p1kpp/4pp2/1B6/1n3Pn1/4P3/PPPP2PP/RNBQK2R w KQ -";
dummy.set_from_fen(fen361);
annotate_move(&dummy,"c2c3","?!");

char fen362[]="r2qk2r/ppp1p2p/5pp1/8/1n1P2b1/N4P2/PPP3PP/R2QKB1R b KQkq -";
dummy.set_from_fen(fen362);
annotate_move(&dummy,"d8d5","!!");

char fen363[]="rn1qkb1r/ppp1p1pp/5p1n/3pP3/8/7B/PPPP1P1P/RNBQK2R b KQkq -";
dummy.set_from_fen(fen363);
annotate_move(&dummy,"h6g4","?!");

char fen364[]="r3kb1r/pp1p2pp/n3pp2/8/6n1/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen364);
annotate_move(&dummy,"f2f4","?!");

char fen365[]="rnbqkbnr/ppp1p1pp/5p2/3p4/3P3N/8/PPP1PPPP/RNBQKB1R b KQkq d3";
dummy.set_from_fen(fen365);
annotate_move(&dummy,"c8g4","?!");

char fen366[]="rnbqkbnr/pppp2pp/8/5pN1/3Pp3/8/PPP1PPPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen366);
annotate_move(&dummy,"e2e3","?!");

char fen367[]="rnbqkbnr/pppp2pp/4pp2/4P3/8/5N2/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen367);
annotate_move(&dummy,"b8c6","?!");

char fen368[]="rnbqkbnr/pppp1ppp/8/4p3/8/5N2/PPPPPPPP/RNBQKB1R w KQkq e6";
dummy.set_from_fen(fen368);
annotate_move(&dummy,"f3g5","!?");

char fen369[]="rnb1kbnr/ppppqN1p/5pp1/4p3/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen369);
annotate_move(&dummy,"f7d6","!");

char fen370[]="rnb1kbnr/pppp1ppp/4p3/3P4/8/6P1/PP2PP1P/3RKBNR b Kkq -";
dummy.set_from_fen(fen370);
annotate_move(&dummy,"f8b4","!!");

char fen371[]="rnbqk1nr/pppp2pp/4pp2/8/1b1P4/2P1PN2/PP3PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen371);
annotate_move(&dummy,"g8h6","?!");

char fen372[]="r1bqkb1r/pppp2pp/4pp1n/8/6P1/1QP5/PP1PPPBP/RNB1K2R b KQkq -";
dummy.set_from_fen(fen372);
annotate_move(&dummy,"c7c6","?!");

char fen373[]="rnb1k1nr/ppp1q1pp/3ppp2/1N6/1b6/2N1P3/PPPP1PPP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen373);
annotate_move(&dummy,"b5d6","?!");

char fen374[]="rnbqkb1r/pppp2pp/4pp1n/3N4/8/7N/PPPPPPPP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen374);
annotate_move(&dummy,"c2c3","!");

char fen375[]="rnbqkbnr/ppp1p1pp/3p1p2/8/8/4PN2/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen375);
annotate_move(&dummy,"f1d3","?!");

char fen376[]="rnbqkbnr/ppp1p1pp/3p1p2/8/8/4PN2/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen376);
annotate_move(&dummy,"f3d4","!?");

char fen377[]="rnbqkbnr/pp1p3p/4ppp1/7Q/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen377);
annotate_move(&dummy,"h5b5","?!");

char fen378[]="rnbqkbnr/pppp2pp/4pp2/8/4P3/5N2/PPPPBPPP/RNBQK2R b KQkq -";
dummy.set_from_fen(fen378);
annotate_move(&dummy,"g8h6","?!");

char fen379[]="rn1qk2r/pp4pp/2p2p1n/3pp3/3PP1P1/b1P5/PP3P1P/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen379);
annotate_move(&dummy,"a3b2","?!");

char fen380[]="rn1qk2r/pp4pp/2p2p1n/2bpp3/3PP1P1/1QP5/PP3P1P/RNB1KB1R b KQkq d3";
dummy.set_from_fen(fen380);
annotate_move(&dummy,"c5a3","?!");

char fen381[]="r1b1kb1r/pppp2pp/4pn2/5p2/1P1PP3/3n1PP1/P1P1Q2P/RNB1K2R w KQkq -";
dummy.set_from_fen(fen381);
annotate_move(&dummy,"e1d1","??");

char fen382[]="r1b1kb1r/pppp2pp/4pn2/5p2/1P1PP3/3n1PP1/P1P1Q2P/RNB1K2R w KQkq -";
dummy.set_from_fen(fen382);
annotate_move(&dummy,"e1f1","?!");

char fen383[]="rnbqkbnr/pppppppp/8/8/8/2P5/PP1PPPPP/RNBQKBNR b KQkq -";
dummy.set_from_fen(fen383);
annotate_move(&dummy,"g8f6","?!");

char fen384[]="r1bqk2r/ppp3p1/2nppp2/1B1P3p/1b2P3/2P2Q2/PP3PP1/RNB1K2R b KQkq -";
dummy.set_from_fen(fen384);
annotate_move(&dummy,"e6e5","?!");

char fen385[]="rnbqk2r/p1pp2p1/1p2pp2/7p/3PPB2/8/PP2BPP1/R2QK2R b KQkq -";
dummy.set_from_fen(fen385);
annotate_move(&dummy,"d7d6","?!");

char fen386[]="rnb1kbnr/pppp2pp/4p3/5p2/8/4P1P1/PPPP1P1P/RNBQK2R b KQkq -";
dummy.set_from_fen(fen386);
annotate_move(&dummy,"b8c6","-");

char fen387[]="rnbqkb2/pp6/2p3p1/3p1p1Q/3Pp3/4P3/PPP2PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen387);
annotate_move(&dummy,"h5h8","!");

char fen388[]="rnb1kbnr/pp1p2pp/2p1pp2/1N6/qP6/4P3/P1PP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen388);
annotate_move(&dummy,"d1h5","!?");

char fen389[]="rnbqk1nr/pppp2pp/4pp2/8/1b6/P1N1PN2/1PPP1PPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen389);
annotate_move(&dummy,"g8h6","?!");

char fen390[]="rnbqkbnr/pp1p2pp/2p1p3/1B3p1Q/4P3/8/PPPP1PPP/RNB1K1NR b KQkq -";
dummy.set_from_fen(fen390);
annotate_move(&dummy,"g7g6","?!");

char fen391[]="rnbqkb1r/ppp1p1pp/3p1p2/1N6/6n1/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen391);
annotate_move(&dummy,"f2f4","!?");

char fen392[]="rnbqk2r/p1pp2p1/1p2pp2/7p/1b1PP3/2P5/PP1NBPP1/R1BQK2R b KQkq -";
dummy.set_from_fen(fen392);
annotate_move(&dummy,"b4c3","?!");

char fen393[]="rnb1kbnr/pppp1ppp/8/4p3/8/8/PPPPPPPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen393);
annotate_move(&dummy,"e2e3","!?");

char fen394[]="rnbqkbnr/p1ppp1pp/8/1p6/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen394);
annotate_move(&dummy,"d1h5","!!");

char fen395[]="rnb1kbnr/pppp3p/4p1p1/5p2/3N4/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen395);
annotate_move(&dummy,"d4b5","?!");

char fen396[]="r1b1kbnr/pppp2pp/2n1p3/5p2/1P6/4P1P1/P1PP1P1P/RNBQK2R b KQkq b3";
dummy.set_from_fen(fen396);
annotate_move(&dummy,"c6e5","-");

char fen397[]="r2k1b1r/pp2p2p/4b1p1/1B1n4/3P4/1P3P2/P1P3PP/RNB1K2R w KQ -";
dummy.set_from_fen(fen397);
annotate_move(&dummy,"c1g5","?!");

char fen398[]="rnb1kb1r/pppp1ppp/4p2n/3N4/3P3q/6P1/PPP1PP1P/R1BQKBNR b KQkq -";
dummy.set_from_fen(fen398);
annotate_move(&dummy,"h4e4","?!");

char fen399[]="r3kb1r/pp2p2p/4bnp1/3p4/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen399);
annotate_move(&dummy,"f1b5","!?");

char fen400[]="r4rk1/p3p2p/6pb/1p1p1b2/3P4/4PB2/PPP3PP/RNB1K2R w KQ -";
dummy.set_from_fen(fen400);
annotate_move(&dummy,"b1a3","?!");

char fen401[]="r1bqkbnr/ppp3pp/2n1pp2/1B1p4/6P1/2P1PN2/PP1P1P1P/RNBQK2R b KQkq -";
dummy.set_from_fen(fen401);
annotate_move(&dummy,"d5d4","?!");

char fen402[]="r1b1kb1r/pppp1p1p/2n1pnp1/8/4P3/2P4P/PP1P1PP1/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen402);
annotate_move(&dummy,"b7b6","?!");

char fen403[]="rnb1k2r/pppp1ppp/4pq1n/8/4P3/2N2N2/PP1P1PPP/R1BQK2R w KQkq -";
dummy.set_from_fen(fen403);
annotate_move(&dummy,"d2d4","??");

char fen404[]="rnb1kb1r/pppp1ppp/4pq1n/8/5PPP/2N5/PPPPP3/R1BQKBNR b KQkq f3";
dummy.set_from_fen(fen404);
annotate_move(&dummy,"f6d4","!!");

char fen405[]="rnbqkbnr/ppppp2p/8/6p1/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen405);
annotate_move(&dummy,"d1h5","!!");

char fen406[]="r1bqkb1r/ppppp1pp/5p1n/8/8/5P2/PPPPP1PP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen406);
annotate_move(&dummy,"e7e6","!?");

char fen407[]="r1b1kb2/pppp4/4p1p1/4np2/1P6/4P1P1/P1PP1P1P/RNB1K2R b KQkq -";
dummy.set_from_fen(fen407);
annotate_move(&dummy,"e5f3","-");

char fen408[]="rnb1kb1r/pp1p1ppp/2p1pq1n/8/2B1P3/5N2/PPPP1PPP/RNBQK2R w KQkq -";
dummy.set_from_fen(fen408);
annotate_move(&dummy,"h2h3","??");

char fen409[]="rnbqkb1r/pppp2p1/4pp2/7p/3PP3/8/PPP1BPP1/RNBQK2R b KQkq d3";
dummy.set_from_fen(fen409);
annotate_move(&dummy,"b7b6","?!");

char fen410[]="rnbqkb1r/1pp3pp/p4p2/3pp3/3PP2N/N7/PPP2PPP/R2QKB1R b KQkq -";
dummy.set_from_fen(fen410);
annotate_move(&dummy,"c8g4","-");

char fen411[]="r4b1r/p1k1p2p/1pB1b1p1/6B1/3P1n2/1PN2P2/P1P3PP/R3K2R w KQ -";
dummy.set_from_fen(fen411);
annotate_move(&dummy,"c3b5","!!");

char fen412[]="rnq1k1nr/p5pp/2p2p2/3pp3/5Qb1/4P3/PPPP1PPP/RNB1K2R w KQkq -";
dummy.set_from_fen(fen412);
annotate_move(&dummy,"f4b4","?!");

char fen413[]="rnbqk1nr/ppp3pp/3ppp2/8/1b1N4/2N1P3/PPPP1PPP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen413);
annotate_move(&dummy,"d4b5","?!");

char fen414[]="rnbqkb1r/ppppp2p/5ppn/8/8/2N1PN2/PPPP1PPP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen414);
annotate_move(&dummy,"f1b5","!");

char fen415[]="r3kb1r/p3p2p/4b1p1/1p1p4/3P2n1/4PP2/PPP3PP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen415);
annotate_move(&dummy,"f3g4","?!");

char fen416[]="r3kb1r/p3p2p/4b1p1/1p1p4/3P2n1/4PP2/PPP3PP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen416);
annotate_move(&dummy,"h2h3","?");

char fen417[]="r1bqk2r/pp4pp/n1p2p1n/3pp3/6PP/B1P5/P2PPP2/RN1QKB1R b KQkq -";
dummy.set_from_fen(fen417);
annotate_move(&dummy,"a6b4","!?");

char fen418[]="r1bqkb1r/pp1pp2p/n1p2ppn/1N5Q/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen418);
annotate_move(&dummy,"b5c7","?!");

char fen419[]="r4rk1/pp5p/4pppn/3p4/1b4P1/2Q1P3/PP1P1P1P/R3KB1R w KQ -";
dummy.set_from_fen(fen419);
annotate_move(&dummy,"f1b5","?!");

char fen420[]="rnq1kbnr/ppp1pN1p/5pp1/3p4/6b1/4PQ2/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen420);
annotate_move(&dummy,"f1b5","?!");

char fen421[]="rnbqkbnr/pppp1ppp/4p3/8/4P3/8/PPPP1PPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen421);
annotate_move(&dummy,"e4e5","??");

char fen422[]="rnbqkbnr/pppp1ppp/4p3/8/4P3/8/PPPP1PPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen422);
annotate_move(&dummy,"d1f3","?!");

char fen423[]="rn1qkbnr/ppp1p2p/4b1p1/3pQ3/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen423);
annotate_move(&dummy,"e5c7","!?");

char fen424[]="rnbqkb2/pp4p1/2p5/3p1p2/3Pp3/4P3/PPP2PPP/RNBQKB1R w KQkq d6";
dummy.set_from_fen(fen424);
annotate_move(&dummy,"d1h5","!");

char fen425[]="rnbqk2r/pppp2pp/4pp1n/8/1b1P4/2P1PN1P/PP3PP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen425);
annotate_move(&dummy,"h6g4","?!");

char fen426[]="rnbqkb1r/pppp2pp/4pp2/3N4/6n1/2P4N/PP1PPPPP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen426);
annotate_move(&dummy,"f2f3","!");

char fen427[]="r3k1nr/pp5p/4ppp1/3p4/1b1Q4/4P3/PP1P1PPP/R3KB1R w KQkq -";
dummy.set_from_fen(fen427);
annotate_move(&dummy,"d4c3","?!");

char fen428[]="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen428);
annotate_move(&dummy,"b1c3","?!");

char fen429[]="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen429);
annotate_move(&dummy,"e2e4","?!");

char fen430[]="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen430);
annotate_move(&dummy,"d2d4","?!");

char fen431[]="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen431);
annotate_move(&dummy,"c2c3","?!");

char fen432[]="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen432);
annotate_move(&dummy,"g1h3","?!");

char fen433[]="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen433);
annotate_move(&dummy,"d2d3","?!");

char fen434[]="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen434);
annotate_move(&dummy,"g2g4","?!");

char fen435[]="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen435);
annotate_move(&dummy,"e2e3","?!");

char fen436[]="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen436);
annotate_move(&dummy,"g1f3","!");

char fen437[]="rn2k1nr/p6p/2p2pp1/3pp3/8/4P3/PPPP1PPP/RNB1K2R w KQkq -";
dummy.set_from_fen(fen437);
annotate_move(&dummy,"b2b4","?!");

char fen438[]="rnbqkb1r/ppppp1pp/5p1n/8/3N4/5P2/PPPPP1PP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen438);
annotate_move(&dummy,"b8c6","!?");

char fen439[]="r2k1b1r/pp5p/4pnp1/1B1p4/8/4P3/PPPP1PPP/RNB1K2R w KQ -";
dummy.set_from_fen(fen439);
annotate_move(&dummy,"f2f3","?!");

char fen440[]="r3k2r/p3p2p/4b1pb/1p1p4/3P4/4P3/PPP3PP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen440);
annotate_move(&dummy,"f1e2","?!");

char fen441[]="rnbqkbnr/pppppppp/8/8/8/7N/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen441);
annotate_move(&dummy,"e7e6","?!");

char fen442[]="rnbqkbnr/pppppppp/8/8/8/7N/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen442);
annotate_move(&dummy,"h7h6","!?");

char fen443[]="rnbqkbnr/pppppppp/8/8/8/7N/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen443);
annotate_move(&dummy,"f7f6","-");

char fen444[]="rnq1k1nr/pp4pp/2p1pp2/1B1p4/6b1/4PQ2/PPPP1PPP/RNB1K2R w KQkq -";
dummy.set_from_fen(fen444);
annotate_move(&dummy,"f3f4","?!");

char fen445[]="rnbqk2r/pppp2pp/4pp1n/8/1b4P1/P1N1PN2/1PPP1P1P/R1BQKB1R b KQkq g3";
dummy.set_from_fen(fen445);
annotate_move(&dummy,"g7g6","?!");

char fen446[]="rnbqkbnr/pppp1ppp/4p3/1B6/8/4P3/PPPP1PPP/RNBQK1NR b KQkq -";
dummy.set_from_fen(fen446);
annotate_move(&dummy,"c7c6","?!");

char fen447[]="b1k5/p1pp4/1p2p1p1/PP6/2NP4/6P1/2PK1P1r/7R b - -";
dummy.set_from_fen(fen447);
annotate_move(&dummy,"d7d6","-");

char fen448[]="r1bqkb1r/pppp2pp/4pp1n/8/8/3P1P2/PPP1P1PP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen448);
annotate_move(&dummy,"h6f5","?!");

char fen449[]="rnbqkb1r/pp1pp2p/2p2ppn/1B6/8/2N1PN2/PPPP1PPP/R1BQK2R w KQkq -";
dummy.set_from_fen(fen449);
annotate_move(&dummy,"c3d5","!");

char fen450[]="rnbqk2r/pppp3p/4pppn/8/1b4P1/P1NBPN2/1PPP1P1P/R1BQK2R b KQkq -";
dummy.set_from_fen(fen450);
annotate_move(&dummy,"b4c3","?!");

char fen451[]="r1b1kb1r/pppp2pp/4pn2/4np2/1P6/4PPP1/P1PP3P/RNBQK2R w KQkq -";
dummy.set_from_fen(fen451);
annotate_move(&dummy,"d2d3","?!");

char fen452[]="r1b1kb1r/pppp2pp/4pn2/4np2/1P6/4PPP1/P1PP3P/RNBQK2R w KQkq -";
dummy.set_from_fen(fen452);
annotate_move(&dummy,"e1g1","?");

char fen453[]="r1b1kb1r/pppp2pp/4pn2/4np2/1P6/4PPP1/P1PP3P/RNBQK2R w KQkq -";
dummy.set_from_fen(fen453);
annotate_move(&dummy,"d2d4","?!");

char fen454[]="rnbqkb1r/ppppp1pp/5p1n/8/3N2P1/8/PPPPPP1P/RNBQKB1R b KQkq g3";
dummy.set_from_fen(fen454);
annotate_move(&dummy,"b8c6","?!");

char fen455[]="rnbqkb1r/ppppp1pp/5p1n/8/3N2P1/8/PPPPPP1P/RNBQKB1R b KQkq g3";
dummy.set_from_fen(fen455);
annotate_move(&dummy,"c7c6","-");

char fen456[]="rnbqkbnr/pppp3p/5pp1/4p1N1/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen456);
annotate_move(&dummy,"g5f7","!");

char fen457[]="r1bq1bnr/pppkpQ1p/2np2p1/8/8/4P3/PPPP1PPP/RNB1KB1R w KQ -";
dummy.set_from_fen(fen457);
annotate_move(&dummy,"f7e7","!!");

char fen458[]="rnbqkb1r/pp1pp2p/2p2ppn/7Q/3N4/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen458);
annotate_move(&dummy,"d4b5","?!");

char fen459[]="r1bqk2r/pp1p2pp/n1p2p1n/4p3/6PP/2P5/P2PPP2/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen459);
annotate_move(&dummy,"d7d5","?!");

char fen460[]="r1bqkb1r/ppppp1pp/2n2p1n/8/3N2P1/2P5/PP1PPP1P/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen460);
annotate_move(&dummy,"c6a5","?!");

char fen461[]="r1bqkb1r/ppppp1pp/2n2p1n/8/3N2P1/2P5/PP1PPP1P/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen461);
annotate_move(&dummy,"c6d4","?");

char fen462[]="rnbqkbnr/ppppp2p/5pp1/6N1/8/4P3/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen462);
annotate_move(&dummy,"f6g5","?!");

char fen463[]="r4b1r/p1k1p2p/1pB1b1p1/3n2B1/3P4/1P3P2/P1P3PP/RN2K2R w KQ -";
dummy.set_from_fen(fen463);
annotate_move(&dummy,"b1c3","!?");

char fen464[]="rnbqkb1r/pp1p2pp/2p2p1n/4p3/1P4P1/1N6/P1PPPP1P/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen464);
annotate_move(&dummy,"f8b4","?!");

char fen465[]="rnb1k2r/pp5p/2p1ppp1/q2p4/2PP4/2N1P2B/P4P1P/R1BQK1R1 b Qkq -";
dummy.set_from_fen(fen465);
annotate_move(&dummy,"d5c4","!!");

char fen466[]="r3kb1r/pp1p2pp/4pp2/8/1n3Pn1/4P3/PPPP2PP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen466);
annotate_move(&dummy,"f1b5","?!");

char fen467[]="2r2rk1/pp5p/4pppn/1B1p4/1b4P1/2Q1P3/PP1P1P1P/R3K2R w KQ -";
dummy.set_from_fen(fen467);
annotate_move(&dummy,"b5e8","?!");

char fen468[]="rnbqkb1r/ppp1p1pp/3p1p1n/8/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen468);
annotate_move(&dummy,"d4b5","!?");

char fen469[]="r1bqkb1r/pppp2pp/4pn2/5p2/8/P3PP2/1PPP2PP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen469);
annotate_move(&dummy,"f6e4","?!");

char fen470[]="rnbq1k1r/ppNp2p1/2pbpp2/7p/3PP3/2P5/PP4PP/R1BQKB1R b KQ -";
dummy.set_from_fen(fen470);
annotate_move(&dummy,"d8e7","??");

char fen471[]="rnbqkb1r/pppp2pp/4pp1n/8/4P3/5N1P/PPPPBPP1/RNBQK2R b KQkq -";
dummy.set_from_fen(fen471);
annotate_move(&dummy,"h6g4","?!");

char fen472[]="rnb1k2r/pp5p/q1p1ppp1/3p4/2PP4/b3P2B/PP2NP1P/R1BQK1R1 w Qkq -";
dummy.set_from_fen(fen472);
annotate_move(&dummy,"b2a3","??");

char fen473[]="r1bqkbnr/ppp3pp/n7/3pppN1/3P4/P7/1PP1PPPP/RNBQKB1R w KQkq d6";
dummy.set_from_fen(fen473);
annotate_move(&dummy,"e2e4","?!");

char fen474[]="rn1qkb1r/pp4pp/2p2p1n/3pp3/4P1P1/1QP5/PP1P1P1P/RNB1KB1R b KQkq e3";
dummy.set_from_fen(fen474);
annotate_move(&dummy,"f8c5","?!");

char fen475[]="r1bqkb1r/ppppp1pp/2n2p1n/1N6/6P1/8/PPPPPP1P/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen475);
annotate_move(&dummy,"c6d4","?!");

char fen476[]="rnbqkbnr/pppp2pp/4p3/5p2/5Q2/4P3/PPPP1PPP/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen476);
annotate_move(&dummy,"d8h4","?!");

char fen477[]="r1bqkb1r/pppp2pp/2n1pp1n/8/3PP3/P4N1P/1PP2PP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen477);
annotate_move(&dummy,"h6g4","!?");

char fen478[]="rnb1kbnr/pppp1ppp/4pq2/8/4P3/2N2N2/PPPP1PPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen478);
annotate_move(&dummy,"f6f4","!!");

char fen479[]="r1bqk2r/ppp3p1/2np1p2/1B1Pp2p/1b2P3/2P3Q1/PP3PP1/RNB1K2R b KQkq -";
dummy.set_from_fen(fen479);
annotate_move(&dummy,"c8g4","?!");

char fen480[]="rnbqkb1r/ppp2ppp/8/3pp3/3PP3/7P/PPP2PP1/RN1QKBNR b KQkq e3";
dummy.set_from_fen(fen480);
annotate_move(&dummy,"g7g6","?!");

char fen481[]="rnq1k1nr/pp5p/2p2pp1/1B1pp3/5Qb1/4P3/PPPP1PPP/RNB1K2R w KQkq -";
dummy.set_from_fen(fen481);
annotate_move(&dummy,"b5a6","?!");

char fen482[]="rnbqk1nr/pppp1ppp/4p3/8/1b6/2PBP3/PP1P1PPP/RNBQK1NR b KQkq -";
dummy.set_from_fen(fen482);
annotate_move(&dummy,"b4c3","-");

char fen483[]="r1bqBbnr/1p2p2p/3pkpp1/8/3P4/4P3/PPP2PPP/RNB1K2R b KQ d3";
dummy.set_from_fen(fen483);
annotate_move(&dummy,"d8a5","??");

char fen484[]="rnbqkb1r/pppppppp/5n2/8/8/2P5/PP1PPPPP/RNBQKBNR w KQkq -";
dummy.set_from_fen(fen484);
annotate_move(&dummy,"d2d4","??");

char fen485[]="rnbqk2r/pppp3p/4ppp1/8/3P4/4P3/PP3PP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen485);
annotate_move(&dummy,"b8a6","?!");

char fen486[]="rnbqkbnr/pppp2pp/4p3/8/8/5Q2/PPPP1PPP/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen486);
annotate_move(&dummy,"f8b4","!");

char fen487[]="3k1b1r/pp2p1pp/7n/3p1p2/6P1/4P3/PPPP1P1P/RNB1K2R w KQ -";
dummy.set_from_fen(fen487);
annotate_move(&dummy,"h1g1","?!");

char fen488[]="r1bq1k1r/p1Np2p1/1ppbpp2/4P2p/3P4/2P5/PP4PP/R1BQK2R b KQ -";
dummy.set_from_fen(fen488);
annotate_move(&dummy,"c8a6","?!");

char fen489[]="rnbqk2r/pppp2pp/4pp2/3P4/1b6/2P1P3/PP3PP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen489);
annotate_move(&dummy,"h7h5","?!");

char fen490[]="rnbqkb1r/pppppppp/7n/8/6P1/2N5/PPPPPP1P/R1BQKBNR b KQkq g3";
dummy.set_from_fen(fen490);
annotate_move(&dummy,"e7e6","?!");

char fen491[]="rn1qkbnr/ppp1p1pp/5p2/3pN3/6b1/4PQ2/PPPP1PPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen491);
annotate_move(&dummy,"g4f3","??");

char fen492[]="rnbqk1nr/pppp3p/4p1p1/8/1b3Q2/2P1P3/PP1P1PPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen492);
annotate_move(&dummy,"d8h4","?!");

char fen493[]="r1bqkb1r/pppp2pp/4pp2/5n2/8/2PP1P2/PP2P1PP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen493);
annotate_move(&dummy,"f5h4","?!");

char fen494[]="rn1qkb1r/1pp4p/p4pp1/3pp3/3PP3/N4P1B/PPP4P/R2QK2R b KQkq -";
dummy.set_from_fen(fen494);
annotate_move(&dummy,"f6f5","?!");

char fen495[]="rnbqkbnr/pppp1pp1/7p/3Np3/8/8/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen495);
annotate_move(&dummy,"d8h4","!!");

char fen496[]="rnbqkbnr/pppp1ppp/4p3/8/4P3/5Q2/PPPP1PPP/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen496);
annotate_move(&dummy,"f7f5","!");

char fen497[]="rnb1kbnr/pppp1ppp/4p3/3P4/2q5/3Q2P1/PPP1PP1P/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen497);
annotate_move(&dummy,"c4c2","!");

char fen498[]="rnbqkb1r/pppp2pp/5p1n/4p3/4P3/2P2N1P/PP1P1PP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen498);
annotate_move(&dummy,"h6g4","!?");

char fen499[]="r1bqkbnr/pp1p3p/2n1ppp1/1Q6/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen499);
annotate_move(&dummy,"b5b7","?!");

char fen500[]="r1bqkbnr/pp1p3p/2n1ppp1/1Q6/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen500);
annotate_move(&dummy,"b5b6","-");

char fen501[]="rnbqkb1r/pp1pp1pp/2p2p1n/8/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen501);
annotate_move(&dummy,"d1h5","?!");

char fen502[]="rnb1kbnr/pppp1ppp/4p3/8/2PP3q/6P1/PP2PP1P/RNBQKBNR b KQkq -";
dummy.set_from_fen(fen502);
annotate_move(&dummy,"h4e4","!!");

char fen503[]="r1b1kb1r/pppp2pp/2n1pn2/5p2/8/2P1PP2/PP1P2PP/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen503);
annotate_move(&dummy,"f8d6","?!");

char fen504[]="rnbqkb1r/ppppp1pp/5p1n/8/6P1/2N2N2/PPPPPP1P/R1BQKB1R b KQkq g3";
dummy.set_from_fen(fen504);
annotate_move(&dummy,"c7c6","?!");

char fen505[]="r1bqkbnr/ppppp1pp/5p2/8/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen505);
annotate_move(&dummy,"d1h5","!!");

char fen506[]="rn1qkbnr/ppp3pp/5p2/3p4/6bN/5P2/PPP1P1PP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen506);
annotate_move(&dummy,"d5d4","!");

char fen507[]="rnbqkbnr/ppppp1pp/5p2/8/8/4PN2/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen507);
annotate_move(&dummy,"d7d5","?!");

char fen508[]="rnbqkbnr/ppppp1pp/5p2/8/8/4PN2/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen508);
annotate_move(&dummy,"d7d6","?!");

char fen509[]="rnbqkbnr/ppppp1pp/5p2/8/8/4PN2/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen509);
annotate_move(&dummy,"e7e6","-");

char fen510[]="rnbqkbnr/ppppp1pp/5p2/8/8/4PN2/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen510);
annotate_move(&dummy,"b8c6","??");

char fen511[]="rnbqkbnr/ppppp1pp/5p2/8/8/4PN2/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen511);
annotate_move(&dummy,"g8h6","??");

char fen512[]="rnbqkbnr/ppppp1pp/5p2/8/8/4PN2/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen512);
annotate_move(&dummy,"b7b5","??");

char fen513[]="rnq1kbnr/pp2pN1p/2p2pp1/1B1p4/6b1/4PQ2/PPPP1PPP/RNB1K2R w KQkq -";
dummy.set_from_fen(fen513);
annotate_move(&dummy,"f3f4","?!");

char fen514[]="rnb1kb1r/pp1p1ppp/2p1pq1n/8/2B1P1P1/5N2/PPPP1P1P/RNBQK2R b KQkq g3";
dummy.set_from_fen(fen514);
annotate_move(&dummy,"f6f4","-");

char fen515[]="r3kb1r/pp1p1ppp/4pn2/8/3P4/8/PPP1PPPP/RN1QKBNR b KQkq -";
dummy.set_from_fen(fen515);
annotate_move(&dummy,"f6g4","!!");

char fen516[]="rnbqkbnr/ppp1p2p/6p1/3p3Q/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen516);
annotate_move(&dummy,"h5e5","!?");

char fen517[]="rnbqkbnr/pppp2pp/5p2/4p3/4P3/5N1P/PPPP1PP1/RNBQKB1R b KQkq e3";
dummy.set_from_fen(fen517);
annotate_move(&dummy,"g8h6","?!");

char fen518[]="rn1qk1nr/ppp3pp/5p2/8/1b1p2bN/3Q1P2/PPP1P1PP/RNBK1B1R b kq -";
dummy.set_from_fen(fen518);
annotate_move(&dummy,"b4d2","!!");

char fen519[]="rn1qkbnr/ppp1p1pp/5p2/3pN3/6b1/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen519);
annotate_move(&dummy,"d1f3","?!");

char fen520[]="r2qkb1r/ppp3pp/2n2p2/1B2p3/3pP3/2PP4/PP3P1P/RN1QK1R1 b Qkq -";
dummy.set_from_fen(fen520);
annotate_move(&dummy,"f6f5","?!");

char fen521[]="rnb1kbnr/pppp1ppp/4p3/8/2PPq3/4P1P1/PP3P1P/RNBQKBNR b KQkq -";
dummy.set_from_fen(fen521);
annotate_move(&dummy,"f8b4","!!");

char fen522[]="r4b1r/ppk1p2p/4b1p1/1B1n2B1/3P4/1P3P2/P1P3PP/RN2K2R w KQ -";
dummy.set_from_fen(fen522);
annotate_move(&dummy,"b5c6","!");

char fen523[]="2k3nr/1p5p/p5p1/3p4/8/1P2P3/P1PP1PPP/4KB1R w KQ -";
dummy.set_from_fen(fen523);
annotate_move(&dummy,"f1e2","?!");

char fen524[]="rnbqkbnr/pppp2pp/8/4ppN1/8/8/PPPPPPPP/RNBQKB1R w KQkq f6";
dummy.set_from_fen(fen524);
annotate_move(&dummy,"h2h4","?!");

char fen525[]="rnbqkbnr/pppp2pp/8/4ppN1/8/8/PPPPPPPP/RNBQKB1R w KQkq f6";
dummy.set_from_fen(fen525);
annotate_move(&dummy,"g2g3","-");

char fen526[]="rnbqkbnr/pppp2pp/8/4ppN1/8/8/PPPPPPPP/RNBQKB1R w KQkq f6";
dummy.set_from_fen(fen526);
annotate_move(&dummy,"d2d4","!?");

char fen527[]="r1bqkb2/pp4p1/n1p5/1B1p4/4Pp2/P7/1PP2PPP/RNBQK2R w KQkq -";
dummy.set_from_fen(fen527);
annotate_move(&dummy,"d1h5","!!");

char fen528[]="r1bqkbnr/pppp2pp/2n1pp2/8/3PP3/P4N2/1PP2PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen528);
annotate_move(&dummy,"g8h6","!?");

char fen529[]="r1b1kb2/pppp4/4p1p1/5p2/1P1P4/4P1P1/P1P2P2/RNB2K2 b kq d3";
dummy.set_from_fen(fen529);
annotate_move(&dummy,"b7b6","?!");

char fen530[]="rnbqkbnr/pp1p2pp/2p1pp2/8/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen530);
annotate_move(&dummy,"d4b5","?!");

char fen531[]="rnbqkb1r/pppppppp/7n/3N4/8/8/PPPPPPPP/R1BQKBNR b KQkq -";
dummy.set_from_fen(fen531);
annotate_move(&dummy,"e7e6","?!");

char fen532[]="rnb1kbnr/pppp1ppp/4p3/3P4/7q/6P1/PPP1PP1P/RNBQKBNR b KQkq -";
dummy.set_from_fen(fen532);
annotate_move(&dummy,"h4c4","!");

char fen533[]="rnbqkbnr/ppppp1pp/8/4Np2/8/8/PPPPPPPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen533);
annotate_move(&dummy,"d7d5","??");

char fen534[]="rnbqkbnr/pppp2pp/8/4p3/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen534);
annotate_move(&dummy,"d1g4","!!");

char fen535[]="rnbqkbnr/ppppp2p/5p2/6p1/8/4PN2/PPPP1PPP/RNBQKB1R w KQkq g6";
dummy.set_from_fen(fen535);
annotate_move(&dummy,"f3e5","!!");

char fen536[]="rnbqk2r/1pp4p/p3ppp1/3p4/3PP1Q1/P1N5/1PP2PPP/R3KB1R b KQkq -";
dummy.set_from_fen(fen536);
annotate_move(&dummy,"e8g8","?!");

char fen537[]="rnbqkb1r/pp1pp1pp/2p5/8/4PPn1/2N4P/PPPP2P1/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen537);
annotate_move(&dummy,"g7g6","?!");

char fen538[]="rnbqkb1r/pp4p1/2p2p2/3pp2p/8/BPN1P1P1/P1PP1P2/R2QKB1R b KQkq -";
dummy.set_from_fen(fen538);
annotate_move(&dummy,"f8b4","?!");

char fen539[]="rnbqkb1r/ppp3pp/5p2/3pp3/3PP3/N4N2/PPP2PPP/R2QKB1R b KQkq -";
dummy.set_from_fen(fen539);
annotate_move(&dummy,"a7a6","?!");

char fen540[]="3qkb1r/p2p2pp/2p1pp1n/8/6P1/2P5/PP1PPPBP/RNB1K2R b KQkq -";
dummy.set_from_fen(fen540);
annotate_move(&dummy,"d8b8","?!");

char fen541[]="r1bqkb1r/pppp2pp/2n1pp2/8/3PP3/P7/1PP2PP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen541);
annotate_move(&dummy,"h7h5","!?");

char fen542[]="r1bqkb1r/pppp2pp/2n1p3/4P2Q/5P2/2P5/PP1P1nPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen542);
annotate_move(&dummy,"g7g6","?!");

char fen543[]="rnbqk1nr/pppp2pp/8/4ppN1/1b1P3P/8/PPP1PPP1/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen543);
annotate_move(&dummy,"c2c3","-");

char fen544[]="r1bqkb1r/pp1pp2p/2n2np1/1B6/8/4PQ2/PPPP1PPP/R1B1K2R w KQkq -";
dummy.set_from_fen(fen544);
annotate_move(&dummy,"f3d5","!!");

char fen545[]="2kr4/p1pp4/bp2p1p1/1P3p2/P2PP3/6P1/2P1KP2/RN6 b - -";
dummy.set_from_fen(fen545);
annotate_move(&dummy,"d8h8","-");

char fen546[]="rnbqkb1r/ppppp1pp/7n/8/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen546);
annotate_move(&dummy,"d1h5","!!");

char fen547[]="r4rk1/p3p2p/4b1pb/1p1p4/3P4/4P3/PPP1B1PP/RNB1K2R w KQ -";
dummy.set_from_fen(fen547);
annotate_move(&dummy,"e2f3","?!");

char fen548[]="rnbqkb1r/pp1pp1pp/2p2p1n/8/3N2P1/8/PPPPPP1P/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen548);
annotate_move(&dummy,"c2c4","??");

char fen549[]="r1bq1k1r/p1Np2p1/1ppbpp2/7p/3PP3/2P5/PP4PP/R1BQK2R w KQ -";
dummy.set_from_fen(fen549);
annotate_move(&dummy,"e4e5","?!");

char fen550[]="rnbqkbnr/pp1pp2p/5pp1/8/8/4PN2/PPPP1PPP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen550);
annotate_move(&dummy,"f3e5","!");

char fen551[]="rn1qkb1r/ppp1p2p/6p1/3p4/8/8/PPPP1P1P/RNBQK2R b KQkq -";
dummy.set_from_fen(fen551);
annotate_move(&dummy,"f8h6","?!");

char fen552[]="r1bqkb1r/ppppp1pp/5p1n/8/3P2P1/2P5/PP2PP1P/RNBQKB1R b KQkq d3";
dummy.set_from_fen(fen552);
annotate_move(&dummy,"b7b6","?");

char fen553[]="r1b1kbnr/pppp2pp/4p3/4np1Q/1P6/4P1P1/P1PP1P1P/RNB1K2R b KQkq -";
dummy.set_from_fen(fen553);
annotate_move(&dummy,"g7g6","-");

char fen554[]="r3k3/p1pp4/bp2p1p1/1P3p2/P2PP3/6P1/2P2P2/RN3K2 b kq -";
dummy.set_from_fen(fen554);
annotate_move(&dummy,"e8c8","-");

char fen555[]="rnbqkb1r/ppppp1pp/5p1n/8/3N4/8/PPPPPPPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen555);
annotate_move(&dummy,"d4b5","??");

char fen556[]="r1bqkbnr/1p1p3p/4ppp1/8/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen556);
annotate_move(&dummy,"f1b5","?!");

char fen557[]="r1bq1k1r/ppNp2p1/2pbpp2/7p/3PP3/2P5/PP4PP/R1BQK2R b KQ -";
dummy.set_from_fen(fen557);
annotate_move(&dummy,"d6f4","?!");

char fen558[]="r1bq1k1r/ppNp2p1/2pbpp2/7p/3PP3/2P5/PP4PP/R1BQK2R b KQ -";
dummy.set_from_fen(fen558);
annotate_move(&dummy,"b7b6","?!");

char fen559[]="r1b2rk1/p1pp1p1p/1p2pnpb/8/4PPP1/7P/PP1P4/RNB1K1NR b KQ -";
dummy.set_from_fen(fen559);
annotate_move(&dummy,"c8a6","?!");

char fen560[]="rnbqk2r/pppp2pp/4pp2/8/1b1P4/2P1P3/PP3PP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen560);
annotate_move(&dummy,"g7g6","?!");

char fen561[]="r3kbnr/pp2p2p/4b1p1/3p4/8/4P3/PPPP1PPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen561);
annotate_move(&dummy,"b7b5","?!");

char fen562[]="r1bqkbnr/ppp4p/4ppp1/1N1p4/3Q4/4P3/PP1P1PPP/R3KB1R w KQkq d6";
dummy.set_from_fen(fen562);
annotate_move(&dummy,"b5c7","?!");

char fen563[]="rnbqkbnr/ppp1p1pp/5p2/3pP3/8/5N2/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen563);
annotate_move(&dummy,"g8h6","?!");

char fen564[]="rn1qk2r/pp4pp/2p2p1n/4p3/3P2P1/2P5/P4P1P/3QKB1R b KQkq -";
dummy.set_from_fen(fen564);
annotate_move(&dummy,"d8b6","?");

char fen565[]="rnb1kb1r/pppp1ppp/4p2n/3N4/7q/5PP1/PPPPP2P/R1BQKBNR b KQkq -";
dummy.set_from_fen(fen565);
annotate_move(&dummy,"h4d4","!!");

char fen566[]="rnbqk2r/pppp2p1/4pp2/3P3p/8/4P3/PP3PP1/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen566);
annotate_move(&dummy,"c7c5","?!");

char fen567[]="rnbqkbnr/pppp2pp/4pp2/8/3N4/4P3/PPPP1PPP/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen567);
annotate_move(&dummy,"f6f5","-");

char fen568[]="rnbqkbnr/pppp2pp/8/4p1N1/3P1p2/8/PPP1PPPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen568);
annotate_move(&dummy,"e2e4","?!");

char fen569[]="rnbqk2r/pppp2pp/4pp2/2bN4/6n1/2P1PP1N/PP1P2PP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen569);
annotate_move(&dummy,"b7b5","?");

char fen570[]="rnbqk2r/pppp2pp/4pp2/2bN4/6n1/2P1PP1N/PP1P2PP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen570);
annotate_move(&dummy,"e8g8","?");

char fen571[]="rnbqk2r/pppp2pp/4pp2/2bN4/6n1/2P1PP1N/PP1P2PP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen571);
annotate_move(&dummy,"c7c6","?!");

char fen572[]="rnb1kbnr/p1pp2pp/4p3/1p3pN1/7q/4P1Q1/PPPP1PPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen572);
annotate_move(&dummy,"c8b7","!");

char fen573[]="rnbqkbnr/ppppp1pp/5p2/8/8/2N4N/PPPPPPPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen573);
annotate_move(&dummy,"g8h6","?!");

char fen574[]="rnbqkbnr/ppppp1pp/5p2/8/8/2N4N/PPPPPPPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen574);
annotate_move(&dummy,"c7c6","-");

char fen575[]="rnq1k1nr/pp4pp/2p2p2/1B1pp3/5Qb1/4P3/PPPP1PPP/RNB1K2R w KQkq -";
dummy.set_from_fen(fen575);
annotate_move(&dummy,"b5a6","?!");

char fen576[]="rnbqkbnr/pppppppp/8/8/8/6P1/PPPPPP1P/RNBQKBNR b KQkq -";
dummy.set_from_fen(fen576);
annotate_move(&dummy,"g8f6","?!");

char fen577[]="rn1qkbnr/ppp1p2p/5pp1/3pN3/6b1/4PQ2/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen577);
annotate_move(&dummy,"e5f7","?!");

char fen578[]="r1bqkb1r/ppppp1pp/5p1n/1N6/3nP1P1/8/PPPP1P1P/RNBQKB1R b KQkq e3";
dummy.set_from_fen(fen578);
annotate_move(&dummy,"d4c2","?!");

char fen579[]="rnbqkbnr/ppp1pppp/3p4/8/8/5N2/PPPPPPPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen579);
annotate_move(&dummy,"f3g5","!");

char fen580[]="r1bqkbnr/ppppp1pp/2n2p2/8/8/4PN2/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen580);
annotate_move(&dummy,"f3e5","!!");

char fen581[]="rnbqkb1r/ppppp1pp/5p1n/8/8/2N2N2/PPPPPPPP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen581);
annotate_move(&dummy,"e2e4","??");

char fen582[]="rnbqkbnr/pppp2pp/4p3/5p2/3N4/4P1P1/PPPP1P1P/RNBQKB1R b KQkq -";
dummy.set_from_fen(fen582);
annotate_move(&dummy,"f8b4","!?");

char fen583[]="rnb1k1nr/pppp1ppp/4pq2/8/1bB1P3/2P2N2/PP1P1PPP/RNBQK2R b KQkq -";
dummy.set_from_fen(fen583);
annotate_move(&dummy,"b4c3","?!");

char fen584[]="rn2kbnr/ppp1p1pp/3q1p2/3pN3/6b1/4PQ2/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen584);
annotate_move(&dummy,"f1b5","?!");

char fen585[]="rnbqk2r/pp1p2pp/2p2p1n/4p3/6PP/8/P1PPPP2/RNBQKB1R b KQkq h3";
dummy.set_from_fen(fen585);
annotate_move(&dummy,"b8a6","?!");

char fen586[]="r1b1kb1r/p1pp1p1p/1pn1pnp1/1B6/4P3/2P4P/PP1P1PP1/RNB1K1NR b KQkq -";
dummy.set_from_fen(fen586);
annotate_move(&dummy,"f8h6","?!");

char fen587[]="r3kb1r/pp1p1ppp/4p3/8/3P2n1/5P2/PPP1P1PP/RN1QKBNR b KQkq -";
dummy.set_from_fen(fen587);
annotate_move(&dummy,"g4e3","!!");

char fen588[]="rnbqkbnr/1ppp2pp/p3pp2/8/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen588);
annotate_move(&dummy,"d4f5","!?");

char fen589[]="rnbqkbnr/ppppp1pp/5p2/8/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq e3";
dummy.set_from_fen(fen589);
annotate_move(&dummy,"d7d5","-");

char fen590[]="rnbqkbnr/ppppp1pp/5p2/8/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq e3";
dummy.set_from_fen(fen590);
annotate_move(&dummy,"e7e6","?!");

char fen591[]="rnbqkbnr/pppp2pp/4pp2/8/3P4/4PN2/PPP2PPP/RNBQKB1R b KQkq d3";
dummy.set_from_fen(fen591);
annotate_move(&dummy,"f8b4","?!");

char fen592[]="rnbqk2r/ppNp2p1/2p1pp2/2b4p/8/2P1P3/PP1P2PP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen592);
annotate_move(&dummy,"e8f8","?!");

char fen593[]="rnbqk2r/ppNp2p1/2p1pp2/2b4p/8/2P1P3/PP1P2PP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen593);
annotate_move(&dummy,"e8f7","??");

char fen594[]="rnbqkbnr/ppp1p1pp/8/3p4/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen594);
annotate_move(&dummy,"d1h5","!?");

char fen595[]="r2k1b1r/pp5p/4pnp1/1B6/3p4/4PP2/PPPP2PP/RNB1K2R w KQ -";
dummy.set_from_fen(fen595);
annotate_move(&dummy,"b5d7","?!");

char fen596[]="r1bqkbnr/pppp2pp/2n1pp2/1B6/3PP3/5N2/PPP2PPP/RNBQK2R b KQkq -";
dummy.set_from_fen(fen596);
annotate_move(&dummy,"f8b4","?!");

char fen597[]="rnbqkbnr/pp1pp2p/6p1/8/8/4P3/PPPP1PPP/R1BQKB1R w KQkq -";
dummy.set_from_fen(fen597);
annotate_move(&dummy,"f1b5","!!");

char fen598[]="2r1kbnr/pp2p2p/4b1p1/3p4/8/4P3/PPPP1PPP/RNB1KB1R w KQk -";
dummy.set_from_fen(fen598);
annotate_move(&dummy,"f1b5","?!");

char fen599[]="rnbqkbnr/pppp1ppp/4p3/7Q/4P3/8/PPPP1PPP/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen599);
annotate_move(&dummy,"g7g6","?!");

char fen600[]="rnb1kbnr/pp1p2pp/2p1pp2/qN6/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen600);
annotate_move(&dummy,"b2b4","!?");

char fen601[]="r1bqkb2/pp6/n1p3p1/1B1p3Q/4Pp2/P7/1PP2PPP/RNB1K2R w KQkq -";
dummy.set_from_fen(fen601);
annotate_move(&dummy,"h5h8","!!");

char fen602[]="rnbqkb1r/ppppp1pp/7n/8/4P3/2N5/PPPP1PPP/R1BQKB1R b KQkq e3";
dummy.set_from_fen(fen602);
annotate_move(&dummy,"h6g4","?!");

char fen603[]="r3kb1r/pp5p/4pnp1/3p4/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen603);
annotate_move(&dummy,"f1b5","-");

char fen604[]="r1bqkbnr/pppp3p/4ppp1/1N6/7Q/4P3/PP1P1PPP/R3KB1R w KQkq -";
dummy.set_from_fen(fen604);
annotate_move(&dummy,"h4d4","?!");

char fen605[]="r1b1kb2/p1pp4/1p2p1p1/5p2/1P1PP3/6P1/P1P2P2/RNB2K2 b kq -";
dummy.set_from_fen(fen605);
annotate_move(&dummy,"f8h6","?!");

char fen606[]="r1bqkbnr/ppppp1pp/2n5/8/8/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen606);
annotate_move(&dummy,"d1h5","!!");

char fen607[]="rnbqk1nr/pppp2pp/8/2b1ppN1/7P/8/PPPPPPP1/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen607);
annotate_move(&dummy,"d2d4","?!");

char fen608[]="r3kbnr/1p2p2p/p3b1p1/3p4/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen608);
annotate_move(&dummy,"b2b3","?!");

char fen609[]="rnbqkbnr/pp2p1pp/2pp1p2/8/3N4/4P3/PPPP1PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen609);
annotate_move(&dummy,"d4b5","?!");

char fen610[]="rnbqkb1r/pp1p2pp/2p2p1n/4p3/3N2P1/1QP5/PP1PPP1P/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen610);
annotate_move(&dummy,"d7d5","?!");

char fen611[]="rnb1kb1r/pppp1p1p/4pnp1/8/4P3/7P/PPPP1PP1/RNB1KBNR b KQkq -";
dummy.set_from_fen(fen611);
annotate_move(&dummy,"b8c6","?!");

char fen612[]="r1bqkbnr/ppp3pp/n7/3pp1N1/3PPp2/P7/1PP2PPP/RNBQKB1R w KQkq -";
dummy.set_from_fen(fen612);
annotate_move(&dummy,"g5h7","?!");

char fen613[]="rnbqkb1r/pppp1ppp/4p2n/8/6PP/2N5/PPPPPP2/R1BQKBNR b KQkq h3";
dummy.set_from_fen(fen613);
annotate_move(&dummy,"d8f6","!");

char fen614[]="rnbqkb1r/pp4pp/2p1Np1n/3pp3/6P1/1QP5/PP1PPP1P/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen614);
annotate_move(&dummy,"c8e6","-");

char fen615[]="rnbqkbnr/pp1p2pp/4pp2/7Q/8/4P3/PPPP1PPP/RNB1KB1R b KQkq -";
dummy.set_from_fen(fen615);
annotate_move(&dummy,"g7g6","?!");

char fen616[]="rnbqkb1r/ppppp1pp/5p1n/3N4/8/7N/PPPPPPPP/R1BQKB1R b KQkq -";
dummy.set_from_fen(fen616);
annotate_move(&dummy,"e7e6","?!");

char fen617[]="r1bqkbnr/ppp1p2p/2np2p1/3Q4/8/4P3/PPPP1PPP/RNB1KB1R w KQkq -";
dummy.set_from_fen(fen617);
annotate_move(&dummy,"d5f7","!!");



	save_annotated_move=true;

	save_anno_book();

}