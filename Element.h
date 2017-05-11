#ifndef ELEMENT_H
#define ELEMENT_H

class Element
{
	Element * previous;
	int content;

	public : 
		Element();
		Element(Element *, int);
		~Element();

		Element * getPrevious();
		void setPrevious(Element *);
		int getContent();
		void setContent(int);
};

#endif