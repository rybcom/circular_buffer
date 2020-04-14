#pragma once

template <class T, std::size_t BUFFER_SIZE>
class circular_buffer
{

	static_assert(BUFFER_SIZE > 0, "buffer of circular must have positive size  ");

#pragma region api

public:


	circular_buffer() noexcept {}

	~circular_buffer(void) noexcept {}

	inline void clear() noexcept
	{
		head_ = 0;
		tail_ = 0;
		is_full_ = false;
	}

	inline void push_back(const T& element) noexcept
	{
		buffer_[tail_] = element;
		tail_ = (tail_ + 1) % (BUFFER_SIZE);

		if (is_full_)
		{
			head_ = (head_ + 1) % (BUFFER_SIZE);
		}

		if (tail_ == head_)
		{
			is_full_ = true;
		}
	}

	inline bool at(std::size_t idx, T* element) const noexcept
	{

		if (size() <= idx) return false;

		std::size_t _idx = (head_ + idx) % (BUFFER_SIZE);
		*element = buffer_[_idx];

		return true;
	}

	inline T& operator[](std::size_t idx) noexcept
	{
		std::size_t _idx = (head_ + idx) % (BUFFER_SIZE);
		return buffer_[_idx];
	}

	inline T const& operator[](std::size_t idx) const noexcept
	{
		std::size_t _idx = (head_ + idx) % (BUFFER_SIZE);
		return buffer_[_idx];
	}

	inline T pop_front() noexcept
	{
		T result = buffer_[head_];
		head_ = (head_ + 1) % BUFFER_SIZE;
		is_full_ = false;
		return result;
	}

	inline std::size_t size() const noexcept
	{
		if (is_full_)
		{
			return BUFFER_SIZE;
		}
		else
		{
			return (BUFFER_SIZE + (tail_ - head_)) % BUFFER_SIZE;
		}
	}

	inline std::size_t capacity() const noexcept
	{
		return BUFFER_SIZE;
	}

	inline std::size_t remaining_capacity() const noexcept
	{
		return (capacity() - size());
	}

	inline bool empty() const noexcept
	{
		return size() == 0;
	}

	inline bool is_full() const noexcept
	{
		return is_full_;
	}

#pragma endregion

#pragma region members
private:

	T buffer_[BUFFER_SIZE];
	std::size_t head_{ 0 };
	std::size_t	 tail_{ 0 };
	bool is_full_{ false };
#pragma endregion

#pragma region iterators
public:

	class const_iterator
	{
	public:
		using value_type = T;
		using reference = T const&;
		using pointer = T const*;
		using iterator_category = std::forward_iterator_tag;
		const_iterator(circular_buffer const& circular_buf) : circular_buffer_{ circular_buf }, is_end{ circular_buf.empty() } {   }
		const_iterator(circular_buffer const& circular_buf, bool isend) : circular_buffer_{ circular_buf }, is_end{ true } {}
		const_iterator operator++() { const_iterator i = *this; ++current_index; check_end(); return i; }
		const_iterator operator++(int) { ++current_index; check_end(); return *this; }

		reference operator*() { return circular_buffer_[current_index]; }
		pointer operator->() { return std::addressof(circular_buffer_[current_index]); }
		bool operator==(const const_iterator& rhs) { return is_end == rhs.is_end; }
		bool operator!=(const const_iterator& rhs) { return is_end != rhs.is_end; }
	private:
		std::size_t current_index{ 0 };
		bool is_end{ false };
		circular_buffer const& circular_buffer_;
		void check_end()
		{
			is_end = current_index == circular_buffer_.size();
		}
	};

	const_iterator cbegin() const
	{
		return const_iterator(*this);
	}
	const_iterator cend() const
	{
		return const_iterator(*this, true);
	}

	const_iterator begin() const
	{
		return const_iterator(*this);
	}
	const_iterator end() const
	{
		return const_iterator(*this, true);
	}

public:

	class iterator
	{
	public:
		using value_type = T;
		using reference = T&;
		using pointer = T*;
		using iterator_category = std::forward_iterator_tag;
		iterator(circular_buffer& circular_buf) : circular_buffer_{ circular_buf }, is_end{ circular_buf.empty() } {   }
		iterator(circular_buffer& circular_buf, bool isend) : circular_buffer_{ circular_buf }, is_end{ true } {}
		iterator operator++() { iterator i = *this; ++current_index; check_end(); return i; }
		iterator operator++(int) { ++current_index; check_end(); return *this; }

		reference operator*() { return circular_buffer_[current_index]; }
		pointer operator->() { return std::addressof(circular_buffer_[current_index]); }
		bool operator==(const iterator& rhs) { return is_end == rhs.is_end; }
		bool operator!=(const iterator& rhs) { return is_end != rhs.is_end; }
	private:
		std::size_t current_index{ 0 };
		bool is_end{ false };
		circular_buffer& circular_buffer_;
		void check_end()
		{
			is_end = current_index == circular_buffer_.size();
		}
	};

	iterator begin()
	{
		return iterator(*this);
	}
	iterator end()
	{
		return iterator(*this, true);
	}

#pragma endregion

};

