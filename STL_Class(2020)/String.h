//-----------------------------------------------------------------------------
// String.h
//
// class String - STL 연습용 클래스 
//	1. 컨테이너의 원소로 사용한다
//  2. char를 저장하는 STL 컨테이너가 되도록 코딩해 나아간다
//  
// 2020. 4.	Programmed by Wulong
//-----------------------------------------------------------------------------
#pragma once

class String_Iterator {
	char* p{ nullptr };
public:
	String_Iterator() {}
	String_Iterator(char* p) : p{ p } { };
	virtual ~String_Iterator() {}

	bool operator!=(const String_Iterator& rhs)const {
		return p != rhs.p;
	}

	String_Iterator& operator++() {
		++p;
		return *this;
	}

	char operator*() {
		return *p;
	}

	bool operator==(const String_Iterator& rhs) const {
		return p == rhs.p;
	}

	ptrdiff_t operator-(const String_Iterator& rhs) const {
		return p - rhs.p;
	}

	ptrdiff_t operator+(const String_Iterator& rhs) const {
		return *p + *rhs.p;
	}

	bool operator<(const String_Iterator& rhs) const {
		return p < rhs.p;
	}

	bool operator>(const String_Iterator& rhs) const {
		return p > rhs.p;
	}

};

// 2020. 4. 26
template <>
struct std::iterator_traits<String_Iterator> {
	using iterator_category = random_access_iterator_tag;
	using value_type = char;
	using difference_type = ptrdiff_t;
	using pointer = char*;
	using reference = char&;
};

class String_Reverse_Iterator {
	char* p{ nullptr };
public:
	String_Reverse_Iterator() {}
	String_Reverse_Iterator(char* p) : p{ p } { };
	virtual ~String_Reverse_Iterator() {}

	bool operator!=(const String_Reverse_Iterator& rhs) const {
		return p != rhs.p;
	}
	String_Reverse_Iterator& operator++() {
		--p;
		return *this;
	}
	char operator*() {
		return *(p - 1);
	}
};


class String {
	size_t len { 0 };
	char* p { nullptr };

public:
	String( );

	String( const char* s );

	virtual ~String( );

	String( const String& other );

	String& operator=( const String& rhs );

	String( String&& other ) noexcept;

	String& operator=( String&& rhs ) noexcept;

	char& operator[]( size_t idx );

	char operator[]( size_t idx ) const;

	size_t size( ) const;

	std::string getString( ) const;

	//비교연산자
	//2020.4.21 추가
	bool operator==(const String&) const noexcept;

	// 2020. 4. 25 추가
	using iterator = String_Iterator;
	using reverse_iterator = String_Reverse_Iterator;

	iterator begin();
	iterator end();

	reverse_iterator rbegin();
	reverse_iterator rend();

	friend std::ostream& operator<<( std::ostream& os, const String& s );
};

