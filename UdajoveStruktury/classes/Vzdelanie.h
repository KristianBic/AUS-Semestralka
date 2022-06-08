class Vzdelanie
{
public:
	Vzdelanie(unsigned bezUkoncenia, unsigned zakladne, unsigned ucnovske, unsigned stredne, unsigned vyssie, unsigned vysokoskolske, unsigned bezVzdelavania, unsigned nezistene) :
		bezUkoncenia_(bezUkoncenia), zakladne_(zakladne), ucnovske_(ucnovske), stredne_(stredne), vyssie_(vyssie), vysokoskolske_(vysokoskolske), bezVzdelavania_(bezVzdelavania), nezistene_(nezistene) {}
	unsigned getNezistene() { return nezistene_; }
	unsigned getBezVzdelavania() { return bezVzdelavania_; }
	unsigned getVysokoskolske() { return vysokoskolske_; }
	unsigned getVyssie() { return vyssie_; }
	unsigned getStredne() { return stredne_; }
	unsigned getUcnovske() { return ucnovske_; }
	unsigned getZakladne() { return zakladne_; }
	unsigned getBezUkoncenia() { return bezUkoncenia_; }
	void setNezistene(unsigned param) { nezistene_ = param; }
	void setBezVzdelavania(unsigned param) {bezVzdelavania_ = param; }
	void setVysokoskolske(unsigned param) { vysokoskolske_ = param; }
	void setVyssie(unsigned param) { vyssie_ = param; }
	void setStredne(unsigned param) {  stredne_ = param; }
	void setUcnovske(unsigned param) {  ucnovske_ = param; }
	void setZakladne(unsigned param) {  zakladne_ = param; }
	void setBezUkoncenia(unsigned param) {  bezUkoncenia_ = param; }
private:
	unsigned nezistene_;
	unsigned bezVzdelavania_;
	unsigned vysokoskolske_;
	unsigned vyssie_;
	unsigned stredne_;
	unsigned ucnovske_;
	unsigned zakladne_;
	unsigned bezUkoncenia_;
};
